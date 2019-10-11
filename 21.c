#include <stdio.h>
#define max_n 10000

int f[max_n + 5] = {0};

void fac(int n) {
    int x = n, sum = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i) continue;
        sum += i + n / i;
    }
    f[x] = sum;
}

int main() {
    for (int i = 1; i < max_n; i++) {
        fac(i);
        f[i] -= i;
    }
    int ans = 0;
    for (int i = 2; i < max_n; i++) {
        if (f[i] < max_n && f[i] != i && f[f[i]] == i) ans += i;
    }
    printf ("%d", ans);
    return 0;
}
