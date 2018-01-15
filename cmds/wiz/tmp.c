// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

#include <net/daemons.h>
#include <net/macros.h>

int main(object me, string arg)
{
	printf("arg=%s\n", arg);

	if (!arg && !stringp(arg))
		return 1;

	printf("%d, %d\n", arg[0], strlen(arg));

	//char c = arg[0];
	//printf("%d, %d, %d\n", c, c > 160, c < 255);

	if (arg[0] > 160 && arg[0] < 255)
		printf("is_chinese() = true\n");
	else
		printf("is_chinese() = false\n");

	printf("%d\n", is_chinese(arg));

    return 1;
}


