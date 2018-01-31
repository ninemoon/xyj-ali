// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

string chinese_number(int i)
{
    return CHINESE_D->chinese_number(i);
}

/// UCS2内码整形数组编码成UTF8字符串
string encode_utf8(int *codes)
{
	return CONVERT_D->encode_utf8(codes);
}

/// 区位码内码整形数组编码成GB2312字符串
string encode_gb2312(int *codes)
{
	return CONVERT_D->encode_gb2312(codes);
}

/// GB2312字符串解码成区位码内码整形数组
int *decode_gb2312(string str)
{
	return CONVERT_D->decode_gb2312(str);
}

/// UTF8字符串解码成UCS2内码整形数组
int *decode_utf8(string str)
{
	return CONVERT_D->decode_utf8(str);
}

int is_chinese(string str)
{
	int *codes = decode_utf8(str);
	for (int i = 0; i < sizeof(codes); i++) {
		if (codes[i] < 0x4E00 && codes[i] > 0x9FBF) // hanzi qujian
			return 0;
	}
	return 1;
}
