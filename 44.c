#include <stdio.h>
#include <inttypes.h>

int64_t pentagonal(int64_t n) {
    return n * (3 * n - 1) / 2;
}

int64_t is_Pentagonal(int64_t x, int64_t n) {
    int64_t head = 1, tail = 10000000000, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (pentagonal(mid) == x) return 1;
        else if (pentagonal(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return 0;
}

int main() {
    int64_t i = 1, j = 1, ans = INT64_MAX;
    while (pentagonal(j + 1) - pentagonal(j) < ans) {
        j += 1;
        i = j - 1;
        for (int i = j - 1; i >= 1 && pentagonal(j) - pentagonal(i) < ans; i--) {
            if (!is_Pentagonal(pentagonal(j) + pentagonal(i), 2 * j)) continue;
            if (!is_Pentagonal(pentagonal(j) - pentagonal(i), 2 * i)) continue;
            if (pentagonal(j) - pentagonal(i) > ans) continue;
            ans = pentagonal(j) - pentagonal(i);
        }
    }
    printf("%" PRId64, ans);
    return 0;
}
