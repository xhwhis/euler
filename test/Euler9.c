#include <stdio.h>
#include <math.h>

int main() {
    int ans, flag = 0;
    for (int i = 1; i < 32; i++) {
        if (flag) break;
        for (int j = i + 1; j < 32; j++) {
            int a = 2 * i * j;
            int b = j * j - i * i;
            int c = j * j + i * i;
            if (1000 % (a + b + c) == 0) {
                ans = a * b * c * pow(1000 / (a + b + c), 3);
                flag = 1;
                break;
            }
        }
    }
    printf ("%d", ans);
    return 0;
}
