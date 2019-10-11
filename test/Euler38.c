#include <stdio.h>
#include <math.h>

int is_val(int num, int *ans) {
    int n = 1, digit = 0;
    int flag[10] = {0};
    while (digit < 9) {
        int mul = num * n;
        while(mul) {
            if (mul % 10 == 0) return 0;
            if (flag[mul % 10]) return 0;
            flag[mul % 10] = 1;
            mul /= 10;
            digit++;
        }
        *ans = *ans * pow(10, floor(log10(num * n)) + 1) + num * n;
        n++;
    }
    return 1;
}

int main() {
    int max = 0;
    for (int i = 1; i < 10000; i++) {
        int ans = 0;
        if (is_val(i, &ans)) {
            if (max < ans) max = ans;
        }
    }
    printf ("%d", max);
    return 0;
}
