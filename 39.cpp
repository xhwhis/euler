#include <iostream>
#define max_n 1000
using namespace std;

int cnt[max_n + 5] = {0};

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    for (int n = 1; n < 33; n++) {
        for (int m = n + 1; m < 33; m++) {
            if (gcd(m, n) - 1) continue;
            int a = m * n * 2;
            int b = m * m - n * n;
            int c = m * m + n * n;
            for (int p = a + b + c; p <= max_n; p += a + b + c) {
                cnt[p]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= max_n; i++) {
        if (cnt[i] > ans) ans = i;
    }
    cout << ans;
    return 0;
}
