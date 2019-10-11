#include <stdio.h>
#include <math.h>
#define max_n 1000000

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > max_n) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int is_val(int n) {
    int digit = floor(log10(n)) + 1;
    int tmp = n, h = (int)pow(10, digit - 1);
    for (int i = 0; i < digit; i++) {
        tmp = (tmp % 10) * h + tmp / 10;
        if(is_prime[tmp]) return 0;
    }
    return 1;
}

int main() {
    init();
    int count = 0;
    for (int i =1; i <= prime[0]; i++) {
        if(is_val(prime[i])) {
            printf("%d\n", prime[i]);
            count++;
        }
    }
    printf ("%d", count);
    return 0;
}
