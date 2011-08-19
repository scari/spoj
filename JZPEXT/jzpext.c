#include <stdio.h>
#include <string.h>
#include <math.h>

#define NOT_BEAUTIFUL (1)
#define BEAUTIFUL (0)
int is_beautiful(unsigned long long n) {
	unsigned long long t = n;
	int digit = 0;
	while(t > 0) {
		digit = t % 10;
		if (digit == 0) {
			t = t / 10;
			continue;
		}
		if (n % digit)
			return NOT_BEAUTIFUL;
		t = t/10;
	}
	printf ("%llu ", n);
	return BEAUTIFUL;
}
void find_beautiful(unsigned long long l, unsigned long long r) {
	unsigned long count = 0;
	unsigned long long i = 0;
	for (i = l; i <= r; i++) {
		if (is_beautiful(i) == BEAUTIFUL)
			count++;
	}
	printf ("\n\n%lu\n", count);
}
int main (int argc, char *argv[]) {
    int testcase = 0;
    unsigned long long l = 0;
    unsigned long long r = 0;

    scanf ("%d\n", &testcase);
    while (testcase--) {
        scanf ("%llu %llu\n", &l, &r);
        find_beautiful(l, r);
    }
    return 0;
}
