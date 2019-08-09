#include <stdio.h>

int main() {
    int p = 1, zero = 0, ans = 0;
    for (int i = 0; num[i]; i++) {
        if (num[i] == '0') {
            zero += 1;
        } else {
            p *= (num[i] - '0');
        }
        if (i >= 13) {
            if (num[i - 13] == '0') {
                zero -=1;
            } else {
                p /= (num[i - 13] - '0');
            }
        }
    }
    return 0;
}
