#include <stdio.h>
#include <math.h>
#define max_n 354294

int is_val (int x) {
    int tmp = x, sum = 0;
    while (x) {
        sum += (int)pow(x % 10, 5);
        x /= 10;
    }
    return sum == tmp;
}

int main() {
    int sum = 0;
    for (int i=2; i<max_n; i++) {
        if (is_val(i)) sum += i;
    }
    printf ("%d",sum);
    return 0;
}
