#include <stdio.h>

int
main (int argc, char *argv[]) {
    int testcases = 0;
    int n = 0;
    int ret = 0;
    int i = 0;
    scanf ("%d", &testcases);
    while (testcases--) {
        scanf ("%d", &n);
        do {
            n = n / 5;
            ret += n;
        } while (n > 0);
        printf ("%d\n", ret);
        ret = 0;
    }
    return 0;
}
