#include <stdio.h>
#define max_n 5000
#define max_m 1000

int fib[max_n + 5][max_m + 5] = {{1, 0}, {1, 1}};

int main() {
    int ans;
    for (int i = 2; i< max_n; i++) {
        fib[i][0] = fib[i - 1][0];
        for (int j = 1; j <= fib[i][0]; j++) {
            fib[i][j] = fib[i - 1][j] + fib[i - 2][j];
        }
        for (int j = 1; j <= fib[i][0]; j++) {
            if (fib[i][j] < 10) continue;
            fib[i][j + 1] += fib[i][j] / 10;
            fib[i][j] %= 10;
            fib[i][0] += (fib[i][0] == j);
        }
        if (fib[i][0] >= max_m) {
            ans = i;
            break;
        }
    }
    printf ("%d", ans);
    return 0;
}
