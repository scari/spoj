#include <stdio.h>
#include <stdlib.h>

#define LENGTH  34500
#define BASE   1000000000L
#define BASEDIGITS 9
typedef long int SHORT;
typedef double   LONG;
typedef long int INDEXER;

SHORT *pi, *powers, *term;
INDEXER size;

void PrintShort(SHORT num) {
    int x;
    int digits[BASEDIGITS + 1];

    for (x = 0; x < BASEDIGITS; x++) {
        digits[x] = num % 10;
        num /= 10;
    }
    for (x = BASEDIGITS - 1; x >= 0; x--) {
        putchar(digits[x]+'0');
    }
}

void Print(SHORT *num) {
    INDEXER x;
    printf("3.");
    for (x = 1; x < size; x++) {
        PrintShort(num[x]);
    }
    printf("\n");
}

void arctan(int multiplier, int denom, int sign) {
    INDEXER x;
    LONG remain, temp, divisor, denom2;
    SHORT NotZero = 1;
    INDEXER adv;

    for (x = 0; x < size; x++)
        powers[x] = 0;

    divisor = 1;
    denom2 = (LONG)denom;denom2 *= denom2;
    adv = 0;

    remain = (LONG)multiplier * denom;
    while (NotZero) {
        for (x = adv; x < size; x++) {
            temp = (LONG)powers[x] + remain;
            powers[x] = (SHORT)(temp / denom2);
            remain = (temp - (denom2 * (LONG)powers[x])) * BASE;
        }

        remain = 0;
        for (x = adv; x < size; x++) {
            temp = (LONG)powers[x] + remain;
            term[x] = (SHORT)(temp / divisor);
            remain = (temp - (divisor * (LONG)term[x])) * BASE;
        }
        remain = 0;

        if (sign > 0) {
            LONG carry, sum;
            carry = 0;
            for (x = size - 1; x >=0; x--) {
                sum = (LONG)pi[x] + (LONG)term[x] + carry;
                carry = 0;
                if (sum >= BASE) {
                    carry = 1;
                    sum -= BASE;
                }
                pi[x] = (SHORT)sum;
            }
        }
        else {
            LONG borrow, sum;
            borrow = 0;
            for (x = size - 1; x >= 0; x--) {
                sum = (LONG)pi[x] - (LONG)term[x] - borrow;
                borrow = 0;
                if (sum < 0) {
                    borrow = 1;
                    sum += BASE;
                }
                pi[x] = (SHORT)sum;
            }
        }

        sign = -sign;
        divisor += 2;
        NotZero = 0;
        for (x = adv; x < size; x++) {
            if (powers[x]) {
                NotZero = 1;
                break;
            }
        }

        if (NotZero) {
            while (powers[adv] == 0)
                adv++;
        }
        /* We can skip ones that are already 0 */
    }
}

int main(int argc, char *argv[]) {
    INDEXER x;
    /*
    if (argc != 2) {
        printf("I need to know how many digits to compute.\n");
        exit(EXIT_FAILURE);
    }

    size = atol(argv[1]);
    if (size <= 0L) {
        printf("Invalid argument.\n");
        exit(EXIT_FAILURE);
    }
    */
    size = LENGTH;

    size = ((size + BASEDIGITS - 1) / BASEDIGITS) + 1;

    pi = malloc(sizeof(SHORT) * size);
    powers = malloc(sizeof(SHORT) * size);
    term = malloc(sizeof(SHORT) * size);
    memset (pi, 0, size);

    arctan(32, 10, 1);
    arctan(4, 239, -1);
    arctan(16, 515, -1);
    Print(pi);
    return EXIT_SUCCESS;
}
