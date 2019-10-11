#include<stdio.h>

int main() {
    int sum3 = (3+999) * 333 /2;
    int sum5 = (5+995) * 199 /2;
    int sum15 = (15+(1000/15)*15)*(1000/15)/2;
    printf("%d", sum3+sum5-sum15);
    return 0;
}
