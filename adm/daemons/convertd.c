inherit F_DBASE;

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

string UTF8toGB2312(string arg)
{
    int *utf8_codes = decode_utf8(arg);
    int *gb_codes = allocate(sizeof(utf8_codes));
    for (int i = 0; i < sizeof(utf8_codes); i++)
    {
        int c = utf8_codes[i];
        if (c < sizeof(U2G_dic))
            gb_codes[i] = U2G_dic[c];
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
        if (c < sizeof(G2U_dic))
            utf8_codes[i] = G2U_dic[c];
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
