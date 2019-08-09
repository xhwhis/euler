#include <stdio.h>

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    int ans = 1;
    for (int i=1; i<=20; i++) {
        if (ans % i == 0) continue;
        ans = ans * i / gcd (ans, i);
    }
    printf("%d", ans);
    return 0;
}
