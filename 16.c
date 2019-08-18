#include <stdio.h>
#define max_n 400

int num[max_n + 5] = {0};

int main() {
    num[0] = num[1] = 1;
    for (int i = 0; i < 1000; i++) {
        for (int j = 1; j <= num[0]; j++) {
            num[j] *= 2;
        }
        for (int k = 1; k <= num[0]; k++) {
            if (num[k] < 10) continue;
            num[k + 1] += num[k] / 10;
            num[k] %= 10;
            num[0] += (k == num[0]);
        }
    }
    int ans = 0;
    for (int i = num[0]; i >= 1; i--) {
        ans += num[i];
    }
    printf ("%d", ans);
    return 0;
}
