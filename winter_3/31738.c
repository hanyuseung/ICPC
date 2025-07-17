#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(void)
{
    bool flag = false;
    long long n, m, tmp = 1;
    scanf("%lld %lld", &n, &m);

    if (n >= m)
        flag = true;
    else{
        for (long long i = 2; i <= n; i++)
        {
            if (i % m){
                tmp = (tmp * (i % m)) % m;
            }
            else{
                flag = true;
                break;
            }
        }
    }

    if (!flag){
        printf("%lld\n", tmp);
    }
    else{
        printf("0\n");
    }
}
