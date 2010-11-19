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

void
show_primes (int m, int n)
{
    int i = 0;
    int j = 0;
    unsigned k = 0;
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
    memset(array, 0, len);

    // fill
    for (i = 0; i < len; i++) {
        if (array[i] == -1)
            continue;
        array[i] = i+m;
        //printf ("array[%d] == %d\n",  i,  array[i]);
        for (j = 2; j < array[i]-1; j++) {
            //printf ("[i]:%d j:%d\n", array[i], j);
            if (!(array[i] % j) && (array[i] != j)) {
                l = i;
                do {
                    k = array[l];
                    array[l] = -1;
                    //printf ("l:%d [l]:%d [l+1]:%d ", l, array[l], array[l+1]);
                    //printf ("k:%d j:%d, m:%d len:%d\n", k, j, m, len);
                    l = ((k*j) - m);
                    if (l >= len)
                        break;
                } while (l >= 0);
                break;
            }
        }
    }
    if (array[0] == 1)
        array[0] = -1;

    /*
    // erathostenes's sieve
    for (i = 0; i < len; i++) {
        for (j = 3; j <= n; j++) {
            //printf ("[%d]: %d %% %d\n", i, array[i], j);
            if (array[i] == -1)
                break;
            if (0 == (array[i] % j) && (array[i] != j)) {
                k = i;
                do {
                    //printf ("remove %d from array\n", array[k]);
                    array[k] = -1;
                    k = (k+1)*j;
                } while (k <= len);
                break;
            }
        }
    }
    */

    // show the prime
    for (i = 0; i < len; i++) {
        if (array[i] != -1)
            printf ("%d\n", array[i]);
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
