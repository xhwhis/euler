#include <stdio.h>

int is_val (int num) {
    int num1=0,num2=num;
    while (num) {
        num1 = num1 * 10 + num % 10;
        num /= 10;
    }
    return num1 == num2;
}

int main () {
    int ans=10201;
    for (int a=100; a<1000; a++) {
        for (int b=ans/a+1; b<=a; b++) {
            if (is_val(a * b) && ans<a*b) ans = a*b;
        }
    }
    printf("%d", ans);
    return 0;
}
