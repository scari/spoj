#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int
main (int argc, char *argv[]) {
    int testcases = 0;
    char n1[20], n2[20], res[20];
    int n1_len = 0, n2_len = 0;
    int distance = 0, carry = 0;
    int i = 0, idx = 0, max_len = 0;;
    int temp = 0;
    scanf("%d", &testcases);
    while (testcases--) {
        scanf("%s %s", n1, n2);
        n1_len = strlen(n1);
        n2_len = strlen(n2);
        distance = n1_len - n2_len;
        if (distance < 0) {
            memset((void *)n1+n1_len, '0', abs(distance));
            n1[n1_len+abs(distance)] = '\0';
        } else if (distance > 0) {
            memset((void *)n2+n2_len, '0', distance);
            n2[n2_len+distance] = '\0';
        }
        max_len = (n1_len > n2_len) ? n1_len : n2_len;
        res[0] = '0';
        carry = 0;
        for (i = 0, idx = 0; i < max_len; i++) {
            temp = (n1[i] - '0') + (n2[i] - '0');
            if (carry)
                temp++;
            if (temp > 9)
                carry = 1;
            else
                carry = 0;
            res[idx] = (temp % 10) + '0';
            if (idx != 0 || res[idx] != '0')
                idx++;
        }
        if (carry)
            res[idx++] = '1';
        else if (idx == 0)
            res[idx++] = '0';

        res[idx] = '\0';
        printf ("%s\n", res);
    }
    return 0;
}
