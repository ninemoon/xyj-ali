
inherit F_DBASE;

#define UTF8_LOWER_LIMIT = 0x9FBF;
#define UTF8_CAPPED = 0x4E00;
#define GB2312_LOWER_LIMIT = 1;

int *G2U_dic = {};
int *U2G_dic = {};

void create()
{
    set("name", "内码精灵");
    foreach (string line in explode(read_file("GB2312toUTF8.dic")))
    {
        G2U_dic += atoi(line);
    }
    foreach (string line in explode(read_file("UTF8toGB2312.dic")))
    {
        U2G_dic += atoi(line);
    }
}

string UTF8toGB2312(string arg)
{
    int *utf8_codes = decode_utf8(arg);
    int *gb_codes = {};
    foreach (int c in utf8_codes)
    {
        if (c > UTF8_LOWER_LIMIT && c < UTF8_CAPPED)
            gb_codes += U2G_dic[c - UTF8_LOWER_LIMIT];
        else
            gb_codes += c;
    }
    return encode_GB2312(gb_codes);
}

string GB2312toUTF8(string arg)
{
    int *gb_codes = decode_GB2312(arg);
    int *utf8_codes = {};
    foreach (int c in gb_codes)
    {
        utf8_codes += G2U_dic[c - GB2312_OFFSET];
    }
    return arg;
}

string output(string arg)
{
    if (!str || !me)
        return str;
    
    if (me->query_encoding() == 1)
    {
        return UTF8toGB2312(str);
    }
    return str;
}

string input(string arg)
{
    if (!str || !me)
        return str;
    
    if (me->query_encoding() == 1)
    {
        return GB2312toUTF8(str);
    }
    return str;
}
