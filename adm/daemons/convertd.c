
inherit F_DBASE;

int *G2U_dic = ({});
int *U2G_dic = ({});

void create()
{
    seteuid(getuid());   // This is required to pass intermud access check.
    set("channel_id", "内码精灵");

    printf("hello world\n");
    string s1 = read_file("GB2312toUTF8.dic");
    printf("s1:%s\n", s1);
    foreach (string line in explode(s1, "\n"))
    {
        G2U_dic += ({ atoi(line) });
    }

    string s2 = read_file("UTF8toGB2312.dic");
    printf("s2:%s\n", s2);
    foreach (string line in explode(s2, "\n"))
    {
        U2G_dic += ({ atoi(line) });
    }
}

string UTF8toGB2312(string arg)
{
    int *utf8_codes = decode_utf8(arg);
    int *gb_codes = ({});
    foreach (int c in utf8_codes)
    {
        gb_codes += ({ U2G_dic[c] });
    }
    return encode_gb2312(gb_codes);
}

string GB2312toUTF8(string arg)
{
    int *gb_codes = decode_gb2312(arg);
    int *utf8_codes = ({});
    foreach (int c in gb_codes)
    {
        utf8_codes += ({ G2U_dic[c] });
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
