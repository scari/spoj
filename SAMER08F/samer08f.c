#include <stdio.h>

int
main (int argc, char *argv[]) {
    int n = 0;
    int ret = 0;
    while (1) {
        scanf ("%d", &n);
        if (n == 0)
            return;
        while (n) {
            ret += n*n;
            n--;
        }
        printf("%d\n", ret);
        ret = 0;
    }
    return 0;
}
