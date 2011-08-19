#include <stdio.h>


int
main (int argc, char *argv[]) {
    int testcases = 0;
    unsigned long long ret = 0;
	unsigned long long n = 0;
    scanf ("%d", &testcases);
    scanf("%llu", &ret);
    while (--testcases){
        scanf("%llu", &n);
		ret ^= n;
    }
	printf ("%llu\n", ret);
    return 0;
}
