#include <stdio.h>

int money[10] = {1, 2, 5, 10, 20, 50, 100, 200};

int get_ans(int n, int m) {
    if (n == 1 || m == 0 || m == 1) return 1;
    if (m < 0) return 0;
    return get_ans(n - 1, m) + get_ans(n, m - money[n - 1]);
}

int main() {
    printf ("%d", get_ans(8, 200));
    return 0;
}
