#include <stdio.h>

int main() {
    int num1=0, num2;
    for (int i=1; i<=100; i++) {
        num1 += i*i;
    }
    int sum=(1+100)*100/2;
    num2 = sum * sum;
    printf ("%d", num2-num1);
    return 0;
}
