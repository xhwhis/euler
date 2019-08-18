#include <iostream>
#include "42.h"
using namespace std;

int triangle(int n) {
    return n * (n + 1) / 2;
}

int binary_search(int(*func)(int), int l, int r, int x) {
    if (l > r) return 0;
    int mid = (l + r) >> 1;
    if (func(mid) == x) return 1;
    if (func(mid) < x) l = mid + 1;
    else r = mid - 1;
    return binary_search(func, l, r, x);
}

int is_val(char *str) {
    int sum = 0;
    for (int i = 0; str[i]; i++) {
        sum += (str[i] - 'A' + 1);
    }
    if (binary_search(triangle, 1, sum, sum)) return 1;
    return 0;
}

int main() {
    int n = sizeof(words) / 100, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (is_val(words[i])) cnt++;
    }
    cout << cnt;
    return 0;
}
