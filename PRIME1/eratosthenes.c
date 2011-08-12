#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRIME (0)
#define NPRIME (1)

int *array = NULL;
int len = 0;

int is_prime (int n) {
    int i = 2;

    if (1 >= n)
        return NPRIME;

    for (i = 2; i < (n/2)+1; i++) {
        if (i == n)
            return PRIME;
        if (!(n % i))
            return NPRIME;
    }
    return PRIME;
}

int mark_prime (int idx) {
    int i = idx;
    array[i] = is_prime(i);
    for (i = i+idx; i < len; i += idx) {
        if (array[i] == NPRIME)
            break;
        array[i] = NPRIME;
    }
}

void print_prime() {
    int i = 0;
    for (i = 2; i < len; i++) {
        if (array[i] == 0) {
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
    array = (int *) malloc (sizeof (int) * len);
    memset(array, PRIME, len);

    array[0] = 1;
    array[1] = 1;
    for (i = 2; i < len; i++) {
        if (array[i] == PRIME) {
            mark_prime(i);
        }
    }

    //print_prime();
    free (array);
    printf ("length: %d\n", len);
    return 0;
}
