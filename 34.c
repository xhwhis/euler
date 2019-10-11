#include <stdio.h>
#define max_n 2540160

int func(int n) {
    if (n == 0) return 1;
    return n*func(n-1);
}

int is_val(int n) {
    int num1=0,num2=n;
    while(n) {
        num1 += func(n % 10);
        n /= 10;
    }
    return num1 == num2;
}

int main () {
    int sum = 0;
    for (int i=10; i<max_n; i++) {
        if(is_val(i)) sum+=i;
    }
    printf ("%d", sum);
    return 0;
}
