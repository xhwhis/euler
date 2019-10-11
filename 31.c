#include <stdio.h>
#define max_m 8
#define max_n 200

int w[max_m + 5] = {1, 2, 5, 10, 20, 50, 100, 200};
int f[max_m + 5][max_n + 5];

int main () {
    for (int i = 0; i < max_m; i++) {
        f[i][0] = 1;
        for (int j = 1; j <= max_n; j++) {
            f[i][j] = 0;
            if (i - 1 >= 0) f[i][j] = f[i - 1][j];
            if (j - w[i] >= 0) f[i][j] += f[i][j - w[i]];
        }
    }
    printf ("%d", f[max_m - 1][max_n]);
    return 0;
}
