#include <stdio.h>

int
adjBC (int n) {
    int ret = 0;
}

int counter (int bit_length, int adjBC) {
	int count = 0;
	
	return count;
}

int
main (int argc, char *argv[]) {
    int testcases = 0;
    int id = 0;
    int adjBC = 0;
    int bit_length = 0;
    int ret = 0;
    scanf ("%d", &testcases);
    while (testcases--) {
        scanf("%d %d %d", &id, &bit_length, &adjBC);
		printf("%d %d\n", counter(bit_length, adjBC));
    }
    return 0;
}
