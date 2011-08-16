#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PRIME (1)
#define NPRIME (0)

unsigned char *sieve;
int len = 0;

int is_prime (int n) {
    int i = 2;
    int sqrt_n = 0;

    if (1 >= n)
        return NPRIME;
    // heuristic
    if (n % 2 == 0)
        return NPRIME;

    sqrt_n = (int) sqrt((double) n) + 1;

    for (i = 2; i < sqrt_n; i++) {
        if (!(n % i))
            return NPRIME;
    }
    return PRIME;
}

void fill_sieve(int m, int n, int len) {
    int i = 0;
    int j = 0;
    if (m == 1)
        sieve[0] = NPRIME;
    // heuristic
    if (m % 2 == 0) {
        for (i = 0; i < len; i += 2)
            sieve[i] = NPRIME;
    } else {
        for (i = 1; i < len; i += 2)
            sieve[i] = NPRIME;
    }

    for (i = 0; i < len; i++) {
        if (sieve[i] == PRIME && is_prime(i+m) > 0) {
            for (j = (i+m)*2; j <= len; j += (i+m))
                sieve[j-1] = NPRIME;
        } else {
            sieve[i] = NPRIME;
        }
    }
}

void print_prime() {
    int i = 0;
    for (i = 2; i < len; i++) {
        if (sieve[i] == PRIME) {
            printf ("%d\n", i);
        }
    }
    return;
}

int main (int argc, char* argv[]) {
    int i = 0;

    if (argc < 2) {
        printf ("missing length\n");
        exit (1);
    }

    len = atoi(argv[1]);
    sieve = (unsigned char *) malloc (sizeof (unsigned char) * len);
    memset(sieve, PRIME, len);

    sieve[0] = 1;
    sieve[1] = 1;
    fill_sieve(2, len, len-2);

    //print_prime();
    free (sieve);
    printf ("length: %d\n", len);
    return 0;
}
