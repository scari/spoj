#include <stdio.h>
#include <sys/time.h>

int main() {
    double sum = 0.0;
    double denominator = 1.0;
    double numerator = 4.0;
    double temp;
    unsigned long long counter = 0;
    int about_to_print = 0;
    int _temp = -1;
    int first = 1;
    while (1) {
        temp = numerator;
        temp /= denominator;
        sum += temp;
        denominator += 2;
        numerator = -numerator;

        _temp = (int)sum;
        if (_temp != about_to_print) {
            about_to_print = _temp;
        } else {
            putchar ('0' + about_to_print);
            if (first) {
                putchar ('.');
                first = 0;
            }
            numerator *= 10;
            _temp = 0;
            about_to_print = 0;
            sum *= 10;
        }
        fflush(stdout);
        /*
        counter++;
        if (counter > 50000) {
            printf("\n");
            break;
        }
        printf ("%1.35f\n", sum);
        */
    }
    return 0;
}
