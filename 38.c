#include <stdio.h>
#include <math.h>
#define max_n 10000

int digits(int n) {
    return floor(log10(n)) + 1;
}

int calc(int x) {
    int n = 1, ans = 0;
    while (digits(ans) < 9) {
        ans *= (int)pow(10, digits(x * n));
        ans += x * n;
        n++;
    }
    if (digits(ans) - 9) return 0;
    int num[10] = {0};
    num[0] = 1;
    int tmp = ans;
    while (tmp) {
        if (num[tmp % 10]) return 0;
        num[tmp % 10]++;
        tmp /= 10;
    }
    return ans;
}

int main() {
    int ans = 0;
    for (int i = 1; i < max_n; i++) {
        int tmp = calc(i);
        if (tmp > ans) ans = tmp;
    }
    printf ("%d", ans);
    return 0;
}
