#include <stdio.h>
#include <inttypes.h>

typedef int64_t int1;

int1 Pentagonal(int1 n) {
    return n * (3 * n - 1) / 2;
}

int1 Hexagonal(int1 n) {
    return n * (2 * n - 1);
}

int1 binary_search(int1 x) {
    int1 head = 1, tail = x, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (Pentagonal(mid) == x) return 1;
        else if (Pentagonal(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int main() {
    int1 n = 144;
    for (;; n++) {
        if (!binary_search(Hexagonal(n))) continue;
        printf ("%" PRId64, Hexagonal(n));
        break;
    }
    return 0;
}
