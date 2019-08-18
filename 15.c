#include <stdio.h>

int main() {
    long long n = 40, m = 20, ans = 1;
    while (m > 1) {
        if (n > 20) ans *= (n--);
        if (m && ans % m == 0) ans /= (m--);
    }
    printf("%lld", ans);
    return 0;
}
