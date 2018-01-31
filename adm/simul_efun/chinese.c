// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

string chinese_number(int i)
{
    return CHINESE_D->chinese_number(i);
}

string encode_utf8(int *codes)
{
	return "";
}

string encode_gb2312(int *codes)
{
	string str = "";

	for (int i = 0; i < sizeof(codes); i++)
	{
		
	}
	return "";
}

int *decode_gb2312(string str)
{
    int *codes = ({});

    for (int i = 0; i < strlen(str); i++) {
    	int code = str[i];
    	if (str[i] < 0x80) { // [0xxxxxxx ~ 10xxxxxx)
    		// ascii
    	} else {
    		code = str[i] - 0xA0;
    		code *= 0x10;
    		code += str[i - 1] - 0xA0;
    		i += 1;
    	}

    	codes += ({ code });
    }
    return codes;
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

int is_chinese(string str)
{
	int *codes = decode_utf8(str);
	for (int i = 0; i < sizeof(codes); i++) {
		if (codes[i] < 0x4E00 && codes[i] > 0x9FBF) // hanzi qujian
			return 0;
	}
	return 1;
}
