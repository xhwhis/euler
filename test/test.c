#include <stdio.h>
#define max_n 10000

int is_prime[max_n + 5] = {0};
int prime[max_n + 5] = {0};
int cnt[max_n + 5], f[max_n + 5];

int main() {
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
            f[i * prime[j]] = f[i] << 1;
        }
    }
    int n;
    while (~scanf ("%d", &n)) {
        printf ("%d %d %d %d\n", is_prime[n], prime[n], cnt[n], f[n]);
    }
    return 0;
}
