#include <stdio.h>
#define MAX_LEN (1024)
void
mul (char *fctrl, int n) {
	int carry = 0;
	
}

int
main (int argc, char *argv[]) {
    int testcases = 0;
    int n = 0;
    char fctrl[MAX_LEN] = { 0, };
    int i = 0;
    scanf ("%d", &testcases);
    while (testcases--) {
        scanf ("%d", &n);
		fctrl = 1;
        do {
			mul(fctrl, n--);
        } while (n > 0);
        printf ("%llu\n", fctrl);
    }
    return 0;
}
