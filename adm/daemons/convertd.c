inherit F_DBASE;

int UNICODE_CN_LOWER_BOUND = 0x9FBF;
int UNICODE_CN_UPPER_BOUND = 0x4E00;

int *G2U_dic = ({});
int *U2G_dic = ({});

void create()
{
    string *lines;

    seteuid(getuid());   // This is required to pass intermud access check.
    set("channel_id", "内码精灵");

    lines = explode(read_file("/adm/daemons/GB2312toUTF8.dic"), "\n");
    G2U_dic = allocate(sizeof(lines));
    for (int i = 0; i < sizeof(lines); i++)
    {
        G2U_dic[i] = atoi(lines[i]);
    }

    lines = explode(read_file("/adm/daemons/UTF8toGB2312.dic"), "\n");
    U2G_dic = allocate(sizeof(lines));
    for (int i = 0; i < sizeof(lines); i++)
    {
        U2G_dic[i] = atoi(lines[i]);
    }
}

int *decode_utf8(string str)
{
    int *codes = ({});
    
    for (int i = 0; i < strlen(str); i++) {
        int code = str[i];
        if (str[i] < 0x80) { // [0xxxxxxx ~ 10xxxxxx)
            // ascii
        } else if (str[i] < 0xC0) { // [10xxxxxx ~ 110xxxxx)
            // error
        } else if (str[i] < 0xE0) { // [110xxxxx ~ 1110xxxx)
            code = str[i] - 0xC0;
            code *= 0x40;
            code += str[i + 1] - 0x80;
            i += 1;
        } else if (str[i] < 0xF0) { // [1110xxxx ~ 11110xxx)
            code = str[i] - 0xE0;
            code *= 0x40;
            code += str[i + 1] - 0x80;
            code *= 0x40;
            code += str[i + 2] - 0x80;
            i += 2;
        } else if (str[i] < 0xF8) { // [11110xx ~ 111110xx)
            code = str[i] - 0xE0;
            code *= 0x40;
            code += str[i + 1] - 0x80;
            code *= 0x40;
            code += str[i + 2] - 0x80;
            code *= 0x40;
            code += str[i + 3] - 0x80;
            i += 3;
        } else { // [111110xx ~ )
            // error
        }
        codes += ({ code });
    }

    return codes;
}

/// GB2312字符串解码成区位码GB2312整形数组
int *decode_gb2312(string str)
{
    int *codes = ({});

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        int code = str[i];
        if (str[i] < 0x80) { // [0xxxxxxx ~ 10xxxxxx)
            // ascii
        } else {
            // gb2312
            code = str[i];
            code *= 0x100;
            code += str[i + 1];
            i += 1;
        }

        codes += ({ code });
    }
    return codes;
}

/// GB2312内码整形数组编码成GB2312字符串
string encode_gb2312(int *codes)
{
    string str = "";

    for (int i = 0; i < sizeof(codes); i++)
    {
        if (codes[i] < 0x80) { // [0xxxxxxx ~ 10xxxxxx)
            // ascii
            string buf = " ";
            buf[0] = codes[i];
            str += buf;
        } else {
            string buf = "  ";
            buf[0] = codes[i] / 0x100;
            buf[1] = codes[i] % 0x100;
            str += buf;
        }
    }
    return str;
}

/// UCS2内码整形数组编码成UTF8字符串
string encode_utf8(int *codes)
{
    string str = "";

    for (int i = 0; i < sizeof(codes); i++)
    {
        if (codes[i] <= 0x7F)
        {
            // * U-00000000 - U-0000007F:  0xxxxxxx
            string buf = " ";
            buf[0] = codes[i];
            str += buf;
        }
        else if (codes[i] >= 0x00000080 && codes[i] <= 0x000007FF )
        {
            // * U-00000080 - U-000007FF:  110xxxxx 10xxxxxx
            string buf = "  ";
            buf[1] = codes[i] % 0x40 + 0x80;
            buf[0] = codes[i] / 0x40 + 0xC0;
            str += buf;
        }
        else if (codes[i] >= 0x00000800 && codes[i] <= 0x0000FFFF)
        {
            // * U-00000800 - U-0000FFFF:  1110xxxx 10xxxxxx 10xxxxxx
            string buf = "   ";
            buf[2] = codes[i] % 0x40 + 0x80;
            buf[1] = codes[i] / 0x40 % 0x40 + 0x80;
            buf[0] = codes[i] / 0x1000 + 0xE0;
            str += buf;
        }
        else if (codes[i] >= 0x00010000 && codes[i] <= 0x001FFFFF)
        {
            // * U-00010000 - U-001FFFFF:  11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
            string buf = "    ";
            buf[3] = codes[i] % 0x40 + 0x80;
            buf[2] = codes[i] / 0x40 % 0x40 + 0x80;
            buf[1] = codes[i] / 0x1000 % 0x40 + 0x80;
            buf[0] = codes[i] / 0x040000 + 0xF0;
            str += buf;
        }
        else if (codes[i] >= 0x00200000 && codes[i] <= 0x03FFFFFF)
        {
            // * U-00200000 - U-03FFFFFF:  111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
            string buf = "     ";
            buf[4] = codes[i] % 0x40 + 0x80;
            buf[3] = codes[i] / 0x40 % 0x40 + 0x80;
            buf[2] = codes[i] / 0x1000 % 0x40 + 0x80;
            buf[1] = codes[i] / 0x040000 % 0x40 + 0x80;
            buf[0] = codes[i] / 0x01000000 + 0xF8;
            str += buf;
        }
        else if (codes[i] >= 0x04000000 && codes[i] <= 0x7FFFFFFF)
        {
            // * U-04000000 - U-7FFFFFFF:  1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
            string buf = "      ";
            buf[5] = codes[i] % 0x40 + 0x80;
            buf[4] = codes[i] / 0x40 % 0x40 + 0x80;
            buf[3] = codes[i] / 0x1000 % 0x40 + 0x80;
            buf[2] = codes[i] / 0x040000 % 0x40 + 0x80;
            buf[1] = codes[i] / 0x01000000 % 0x40 + 0x80;
            buf[0] = codes[i] / 0x40000000 + 0xFC;
            str += buf;
        }
    }
    return str;
}

string UTF8toGB2312(string arg)
{
    int *utf8_codes = decode_utf8(arg);
    int *gb_codes = allocate(sizeof(utf8_codes));
    for (int i = 0; i < sizeof(utf8_codes); i++)
    {
        int c = utf8_codes[i];
        if (c < UNICODE_CN_UPPER_BOUND && c > UNICODE_CN_LOWER_BOUND)
            gb_codes[i] = U2G_dic[c - UNICODE_CN_LOWER_BOUND];
        else
            gb_codes[i] = c;
    }
    return encode_gb2312(gb_codes);
}

string GB2312toUTF8(string arg)
{
    int *gb_codes = decode_gb2312(arg);
    int *utf8_codes = allocate(sizeof(gb_codes));
    for (int i = 0; i < sizeof(gb_codes); i++)
    {
        int c = gb_codes[i];
        if (c > 0x8080)
            utf8_codes[i] = G2U_dic[c - 0x8080];
        else
            utf8_codes[i] = c;
    }
    return arg;
}

string output(string str, object me)
{
    if (!str || !me)
        return str;
    
    if (me->query_encoding() == 1)
    {
        return UTF8toGB2312(str);
    }
    return str;
}

string input(string str, object me)
{
    if (!str || !me)
        return str;
    
    if (me->query_encoding() == 1)
    {
        return GB2312toUTF8(str);
    }
    return str;
}
