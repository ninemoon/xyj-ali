// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
int judge(string str)
{
	int *codes = convert_utf8(str);
	for (int i = 0; i < sizeof(codes); i++) {
		if (codes[i] < 0x4E00 && codes[i] > 0x9FBF) // hanzi qujian
			return 0;
	}
	return 1;
}

int main(object me, string arg)
{
	printf("arg=%s\n", arg);

	if (!arg || !stringp(arg) || sizeof(arg) < 3)
		return 1;

	printf("%d, %d\n", arg[0], strlen(arg));
	printf("%x, %x, %x\n", arg[0], arg[1], arg[2]);

	printf("%O\n", convert_utf8(arg));
	printf("%d\n", judge(arg));

    return 1;
}


