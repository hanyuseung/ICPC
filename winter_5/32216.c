#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int k,n,T0,bull = 0;
    scanf("%d %d %d",&n, &k, &T0);
    int* d = (int*)malloc(sizeof(int)*(n+1));
    int* T = (int*)malloc(sizeof(int)*(n+1));
    T[0] = T0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&d[i+1]);
        if(T[i] > k)
            T[i+1] = T[i] + d[i+1] - (T[i]-k > 0 ? T[i]-k : k-T[i]);
        else if(T[i] < k)
            T[i+1] = T[i] + d[i+1] + (T[i]-k > 0 ? T[i]-k : k-T[i]);
        else
            T[i+1] = T[i] + d[i+1];
        bull += (T[i+1]-k > 0 ? T[i+1]-k : k-T[i+1]);
    }
    printf("%d\n",bull);
}