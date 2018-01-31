// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
int main(object me, string arg)
{
	int *codes;
	string buf;
	seteuid(getuid());

	printf("arg=%s\n", arg);

	if (!arg || !stringp(arg) || sizeof(arg) < 2)
		return 1;

	printf("%d, %d\n", arg[0], strlen(arg));
	printf("%x, %x\n", arg[0], arg[1]);

	codes = decode_gb2312(arg);
	printf("%O\n", codes);
	buf = encode_gb2312(codes);
	printf("converted: %s\n", buf);

    return 1;
}


