#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PRB_PRIME       (1)
#define COMPOSITE   (0)
#define K           (1)
static unsigned long long next = 1;
unsigned long long llrand () {
    next = next * 17;
    return next;
}

int miller_rabin (unsigned long long n, int k) {
    unsigned long long s = 0, temp = 0, r = 0, a = 0, mod = 0;
    if (n < 2)
        return COMPOSITE;
    if (n <= 3)
        return PRB_PRIME;
    if (n != 2 && n % 2 == 0)
        return COMPOSITE;

    s = n - 1;
    while (s % 2 == 0)
        s >>= 1;

    while (k--) {
        //r = llrand(n - 1);
        r = random();
        a = r + 1;
        temp = s;
        mod = ((unsigned long long )powl((long double)a,(long double)temp)) % n;
        while (temp != n-1 && mod != 1 && mod != n-1) {
            mod = (mod*mod)%n;
            temp = temp*2;
        }
        if (mod != n-1 && temp%2 == 0)
            return COMPOSITE;
    }
    return PRB_PRIME;
}
int main (int argc, char* argv[]) {
    int testcases = 0;
    unsigned long long n = 0;

    scanf("%d", &testcases);
    while (testcases--) {
        scanf("%lld", &n);
        if (PRB_PRIME == miller_rabin(n, K))
            printf ("YES\n");
        else
            printf ("NO\n");
    }
    return 0;
}
