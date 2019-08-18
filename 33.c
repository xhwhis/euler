#include <stdio.h>

int is_val(int i, int j) {
    int num1 = i, num2 = j;
    if (i == j) return 0;
    else if (i % 10 ==0 && j % 10 == 0) return 0;
    else if (i / 10 == j/10) {
        i %= 10;
        j %= 10;
    } else if (i / 10 == j%10) {
        i %=10;
        j /=10;
    } else if (i % 10 == j/10) {
        i /= 10;
        j %= 10;
    } else if (i % 10 == j % 10) {
        i /= 10;
        j /= 10;
    } else return 0;
    return num1 * j == num2 * i;
}

int main() {
    int num[100];
    for (int i = 10; i <= 99; i++) {
        for (int j = i; j <= 99; j++) {
            if (is_val(i, j)) printf ("%d / %d\n", i, j);
        }
    }
    return 0;
}
