#include <stdio.h>
#define max_n 15000

int is_prime[max_n + 5] = {0};
int prime[max_n + 5] = {0};
int cnt[max_n + 5], f[max_n + 5];

void init() {
    f[1] = 1;
    for (int i = 2; i <= max_n ; i++) {
        if (!is_prime[i]) {
            prime[++prime[0]] = i;
            cnt[i] = 1;
            f[i] = 2;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                cnt[i * prime[j]] = cnt[i] + 1;
                f[i * prime[j]] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                break;
            }
            cnt[i * prime[j]] = 1;
            f[i * prime[j]] = f[i] << 1;
        }
    }
    return ;
}

int main() {
    init();
    int n = 1, num;
    while (1) {
        num = (n & 1 ? (f[n] * f[(n + 1) >> 1]) : (f[n + 1] * f[n >> 1]));
        if (num > 500) break;
        n++;
    }
    printf ("%d", n * (n + 1) >> 1);
    return 0;
}
