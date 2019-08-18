#include <stdio.h>
#define max_m 8
#define max_n 200

int w[max_m + 5] = {1, 2, 5, 10, 20, 50, 100, 200};
int f[max_n + 5] = {0};

int main () {
    f[0] = 1;
    for (int i = 0; i < max_m; i++) {
        for (int j = 1; j <= max_n; j++) {
            if (j - w[i] >= 0) f[j] += f[j - w[i]];
        }
    }
    printf ("%d", f[max_n]);
    return 0;
}
