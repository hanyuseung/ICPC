#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int abs(int a)
{
    if(a >= 0)
        return a;
    else
        return -a;
}

bool check(int A, int B, int p, int q, int *trace)
{
    if (p == q)  
        return (A == B) ? (*trace = 0, true) : false;

    if ((B - A) % (p - q) == 0 && (B - A) / (p - q) >= 0) {
        *trace = abs((B - A) / (p - q));
        return true;
    }

    return false;
}

int main(void)
{
    int n, p, q;
    scanf("%d %d %d", &n, &p, &q);
    int *A = (int *)malloc(sizeof(int) * (n));
    int *B = (int *)malloc(sizeof(int) * (n));
    int *trace = (int *)malloc(sizeof(int) * (n));
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &B[i]);
    for (int i = 0; i < n; i++)
    {
        if(!check(A[i],B[i],p,q, &trace[i])){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    for (int i = 0; i < n; i++)
        printf("%d ",trace[i]);
    printf("\n");
    free(A); free(B); free(trace);
    return 0;
}