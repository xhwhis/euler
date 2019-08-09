#include <stdio.h>
#include <string.h>
#define max_n 10000

int prime[max_n + 5];

int main() {
    memset (prime, 0, sizeof(prime));
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            for (int j = 2; j * i <= max_n; j++) {
                prime[j * i] = 1;
            }
        }
    }
    int num;
    scanf("%d", &num);
    for (int i=1; i<=max_n; i++) {
        if (num % prime[i] == 0) {
            printf("%d",prime[i]);
            break;
        }
    }
    return 0;
}
