#include <stdio.h>
#define EXP_LEN	(400)

char*
rnp (const char *exp, char *ret)
{
	int len = strlen (exp);
	int i = 0, rnp_idx = 0;
	char c = '\0';
	for (i = 0; i < len; i++) {
		c = exp[i];

		switch (c) {
			case 'a'...'z':
				ret[rnp_idx++] = c;
				break;
			case '*':
			case '/':
			case '^':
				break;
			case '+':
			case '-':
			case '(':
			case ')':
				break;
		}
	}
	return ret;
}
int
main (int argc, char *argv[])
{
	int testcases = 0;
	char exp[EXP_LEN] = { 0, };
	char ret[400] = { 0, };
	scanf ("%d", &testcases);
	while (testcases--)
	{
		memset (exp, 0, EXP_LEN);
		memset (ret, 0, EXP_LEN);
		scanf ("%s", exp);
		printf ("%s\n", rnp(exp, ret));
		//printf ("%s\n", exp);
	}
	return 0;
}
