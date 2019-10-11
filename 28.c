#include <stdio.h>

int main() {
    int sum = 1;
    for (int n = 3; n <= 1001; n += 2) {
        sum += 4 * n * n - 6 * n + 6;
    }
    printf ("%d", sum);
    return 0;
}
