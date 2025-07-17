#include <stdio.h>

int main(void)
{
    long long R, interver, m;
    scanf("%lld %lld %lld",&R, &interver, &m);
    long long n = m/interver;
    if(n >= 63)
        n = 63;
    R >>= n;
    printf("%lld\n",R); 
}