#include <stdio.h>
#define max_n 2000003

int prime[max_n + 5] = {0};

int main() {
    long long sum = 0;
    for (int i =2; i <= max_n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i=1; prime[i]<2000000; i++){
        sum += prime[i];
    }
    printf ("%lld",sum);
    return 0;
}
