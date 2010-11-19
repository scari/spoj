#include <stdio.h>

int
main (int argc, char *argv[])
{
    int input = 0;
    while (1) {
        scanf ("%d\n", &input);
        if (42 == input)
            return 0;
        printf ("%d\n", input);
    }
}

