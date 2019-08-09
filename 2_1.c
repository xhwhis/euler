#include<stdio.h>

int Fib(int n) {
    if(n==1) return 1;
    if(n==2) return 2;
    return Fib(n-1)+Fib(n-2);
}

int main () {
    int sum = 0;
    for (int i=2; i<45, Fib(i)<=4000000; i+=3) {
        sum+=Fib(i);
    }
    printf("%d", sum);
    return 0;
}
