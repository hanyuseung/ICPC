#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n,m,tmp,bill = 0;
    scanf("%d",&n);
    int* A = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
        scanf("%d",&A[i]);
    scanf("%d",&m);
    for (int i = 0; i < m; i++){
        scanf("%d",&tmp);
        bill += A[tmp-1];
    }
    printf("%d\n",bill);
    free(A);
}