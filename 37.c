#include <stdio.h>
#include <math.h>
#define max_n 1000000

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};

void init() {
    for (int i =2; i <= max_n; i++) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int is_val(int n) {
    int digit = floor(log10(n)) + 1, num1 = n, num2 = n, flag = 0;
    for (int i = 1; i < digit; i++) {
        num1 /= 10;
        num2 = n % (int)pow(10, i);
        if (is_prime[num1] || is_prime[num2] || num1 == 1 || num2 == 1) return 0;
    }
    return 1;
}

int main() {
    init();
    int sum = 0;
    for (int i = 5; i <= prime[0]; i++) {
        if (is_val(prime[i])) {
            printf("%d\n", prime[i]);
            sum += prime[i];
        }
    }
    printf ("answer is %d", sum);
    return 0;
}
