#include<stdio.h>

int main() {
    int a=1, b=2, sum=2;
    while (a+b<4000000) {
        b=a+b;
        a=b-a;
        if(!(b&1)) sum+=b;
    }
    printf("%d", sum);
    return 0;
}
