#include <iostream>
#include <cstring>
#define max_n 1000
using namespace std;

int keep[max_n + 5] = {0};

int get_len(int x) {
    memset(keep, 0, sizeof(keep));
    int r = 1, t = 1;
    keep[1] = 1;
    while (r) {
        r *= 10;
        r %= x;
        t++;
        if (keep[r]) return t - keep[r];
        keep[r] = 1;
    }
    return 0;
}

int main() {
    int d = 0, len = 0;
    for (int i = 1; i < max_n; i++) {
        int temp = get_len(i);
        if (temp > len) {
            len = temp;
            d = i;
        }
    }
    printf ("%d %d", d, len);
    return 0;
}
