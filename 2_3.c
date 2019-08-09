#include<stdio.h>

int main() {
    int fib[3]={0,1}, n=1, sum=0;
    while (fib[n%3] + fib[(n-1)%3]<4000000) {
        n++;
        fib[n%3] = fib[(n-1)%3] + fib[(n-2)%3];
        if (!(fib[n%3]&1)) sum+=fib[n%3];
    }
    printf("%d", sum);
    return 0;
}
