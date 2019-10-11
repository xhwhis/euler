#include <stdio.h>

int a[30][30] = {0};
int dir[4][2] = {0, 1, 1, 1, 1, 0, 1, -1};

int main() {
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int max = 0;
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            for (int k = 0; k < 4; k++) {
                int mul = 1;
                for (int l = 0; l < 4; l++) {
                    mul *= a[i + dir[k][0] * l][j + dir[k][1] * l];
                }
                if (max < mul) max = mul;
            }
        }
    }
    printf("%d", max);
    return 0;
}
