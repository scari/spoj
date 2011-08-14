#include <stdio.h>
#define EXP_LEN	(400)

char*
rnp (const char *exp)
{
	int len = strlen (exp);
	int i = 0;
	char c = '\0';
	for (i = 0; i < len; i++) {
		c = exp[i];

		switch (c) {
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
	return NULL;
}
int
main (int argc, char *argv[])
{
	int testcases = 0;
	char exp[EXP_LEN] = { 0, };
	scanf ("%d", &testcases);
	while (testcases--)
	{
		memset (exp, 0, EXP_LEN);
		scanf ("%s", exp);
		printf ("%s\n", rnp(exp));
		//printf ("%s\n", exp);
	}
	return 0;
}
