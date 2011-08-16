#include <stdio.h>
#include <string.h>
#include <math.h>

#define PRIME	(1)
#define NPRIME	(0)
// return true if n is prime
unsigned char *sieve;

int is_prime (int n) {
    int i = 2;
	int sqrt_n = 0;

    if (1 >= n)
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

	for (i = 0; i < len; i++) {
		if (sieve[i] == PRIME && is_prime(i+m) > 0) {
			for (j = (i+m)*2; j <= len; j += (i+m))
				sieve[j-1] = NPRIME;
		} else {
			sieve[i] = NPRIME;
		}
	}
}

void show_primes (int m, int n) {
    int i = 0;
    int len = 0;

    // make M <= N
    if (m > n)
        m ^= n ^= m ^= n;   // swap

    len = n - m + 1;
	sieve = (unsigned char *) malloc (sizeof (unsigned char) * len);

	memset (sieve, PRIME, len);
	fill_sieve(m, n, len);
    // show the prime
    for (i = 0; i < len; i++) {
        //if (is_prime(i + m))
        if (sieve[i] == PRIME)
            printf ("%d\n", i + m);
    }
	free (sieve);
}

int main (int argc, char *argv[]) {
    int testcase = 0;
    int m = 0;
    int n = 0;

    scanf ("%d\n", &testcase);
    while (testcase--) {
        scanf ("%d %d\n", &m, &n);
        show_primes (m, n);
        printf ("\n");
    }
    return 0;
}
