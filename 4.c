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
    int ans;
    for (int i=100; i<1000; i++) {
        for (int j=i; j<1000; j++) {
            if (is_val(i * j) && ans < i * j) ans = i * j;
        }
    }
    printf("%d", ans);
    return 0;
}
