#include <stdio.h>
#define max_n 2540160

int num[10];

void init(int *num) {
    num[0] = 1;
    for (int i=1; i<10; i++) {
        num[i] = num[i-1] * i;
    }
}

int is_val(int n) {
    int num1=0,num2=n;
    while(n) {
        num1 += num[n % 10];
        n /= 10;
    }
    return num1 == num2;
}

int main () {
    int sum = 0;
    init(num);
    for (int i=10; i<max_n; i++) {
        if(is_val(i)) sum+=i;
    }
    printf ("%d", sum);
    return 0;
}
