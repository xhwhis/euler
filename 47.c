#include <stdio.h>
#define max_n 1000000

int prime[max_n + 5] = {0};
int val[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            val[i] = 1;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                val[prime[j] * i] = val[i];
                break;
            } else {
                val[prime[j] * i] = val[i] + 1;
            }
        }
    }
    return ;
}

int main() {
    init();
    for (int i = 6; i <= max_n - 3; i++) {
        if (val[i] != 4) continue;
        if (val[i] != val[i + 1]) continue;
        if (val[i + 1] != val[i + 2]) continue;
        if (val[i + 2] != val[i + 3]) continue;
        printf ("%d", i);
        break;
    }
    return 0;
}
