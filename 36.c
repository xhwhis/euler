#include <stdio.h>
#define max_n 1000000

int is_val(int num, int n) {
    int num1 = 0, num2 = num;
    while (num) {
        num1 = num1 * n + num % n;
        num /= n;
    }
    return num1 == num2;
}

int main() {
    int sum = 0;
    for (int i=1; i<=max_n; i++) {
        if(is_val(i, 10) && is_val(i,2)) sum += i;
    }
    printf ("%d", sum);
    return 0;
}
