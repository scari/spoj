#include <stdio.h>
#include <string.h>

// return true if n is prime
int
is_prime (int n)
{
    int i = 2;

    if (1 >= n)
        return 0;

    for (i = 2; i < n; i++) {
        if (!(n % i))
            return 0;
    }
    return 1;
}
int
mark_multiple_of (int index, int multiple_of, int min) {
    //printf ("(%d+%d) %% %d\n", index, min, multiple_of);
    if ((index+min) == 1)
        return -1;

    if ((index+min) == multiple_of)
        return 1;

    if (((index+min)%multiple_of) == 0)
        return -1;
}

void
show_primes (int m, int n) {
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int len = 0;
    int *array = NULL;

    // make M <= N
    if (m > n)
        m ^= n ^= m ^= n;   // swap

    len = n - m + 1;
    array = (int *) malloc (sizeof (int) * len);
    if (NULL == array) {
        printf ("malloc failed!\n");
        return;
    }
    memset(array, 1, len);

    // erathostenes's sieve
    for (i = 0; i < len; i++) {
        for (j = m; j > 1; j--) {
            if (array[i] >= 0) {
                if (0 > mark_multiple_of (i, j, m)) {
                    array[i] = -1;
                    /*
                    for (k = i; k < len; k += k) {
                        array[k] = -1;
                    }
                    */
                }
            }
        }
        for (j = m; j <= (n/2); j++) {
            if (array[i] >= 0 && j > 1) {
                if (0 > mark_multiple_of (i, j, m)) {
                    array[i] = -1;
                    /*
                    for (k = i; k < len; k += k) {
                        array[k] = -1;
                    }
                    */
                }
            }
        }
    }
    // show the prime
    for (i = 0; i < len; i++) {
        if (array[i] != -1)
            printf ("%d\n", i + m);
    }
    free (array);
}

int
main (int argc, char *argv[])
{
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
