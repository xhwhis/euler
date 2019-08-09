#include<stdio.h>

int main() {
    long long n=600851475143, ans=0;
    for(long long i=2; i*i<=n; i++) {
        if (n % i == 0) ans=i;
        while (n % i == 0) n/=i;
    }
    if (n!= 1) ans=n;
    printf("%lld", ans);
    return 0;
}
