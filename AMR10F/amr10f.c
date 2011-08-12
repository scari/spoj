#include <stdio.h>

int
main (int argc, char *argv[]) {
    int testcases = 0;
    int n, a, d, i;
    int res = 0;

    scanf ("%d", &testcases);

    while (testcases--) {
        scanf ("%d %d %d", &n, &a, &d);
        res = n * a;
        for (i = 0; i < n; i++) {
            res += i*d;
        }   
        printf ("%d\n", res);
    }   
    return 0;
}
