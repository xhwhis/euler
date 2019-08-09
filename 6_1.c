#include <stdio.h>

int main() {
    int n = 100;
    int sum1 = (1 + n) * n / 2;
    int sum2 = n * (n + 1) * (2 * n + 1) / 6;
    printf ("%d", sum1 * sum1 - sum2);
    return 0;
}
