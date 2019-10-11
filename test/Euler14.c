#include<stdio.h>
#define max_n 1000000

int keep[max_n];

int get_len(long long x) {
    if (x == 1) return 1;
    if (x <= max_n && keep[x]) return keep[x];
    int ret;
    if (x & 1) ret = get_len(3 * x + 1) + 1;
    else ret = get_len(x >> 1) + 1;
    if (x <= max_n) keep[x] = ret;
    return ret;
}

int main() {
    int max = 0, ans;
    for (int i = 1; i < max_n; i++) {
        int l = get_len(i);
        if (l > max) max = l, ans = i;
    }
    printf("%d", ans);
    return 0;
}
