#include<stdio.h>
#define max_n 1000000

long long get_len(long long x) {
    if (x == 1) return 1;
    if (x & 1) return get_len(x * 3 + 1) + 1;
    return get_len(x >> 1) + 1;
}

int main() {
    int ans = 0, num = 0;
    for (int i = 1; i < max_n; i++) {
        int l = get_len(i);
        if (l > ans) ans = l, num = i;
    }
    printf("%d", num);
    return 0;
}
