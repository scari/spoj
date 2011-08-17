#include <stdio.h>
int main(int argc, char* argv[]) {
    int t=0,n=0,r=0;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        if (n>0) r+=n;
    }
    printf("%d\n",r);
    return 0;
}
