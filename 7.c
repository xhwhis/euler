#include <stdio.h>
#include <string.h>
#define max_n 200000

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
    printf ("%d", prime[10001]);
    return 0;
}
