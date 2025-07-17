#include<stdio.h>
#include<stdlib.h>


int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(void)
{
    int p, n, count = 0;
    int i = 0;
    int* a;
    scanf("%d %d",&p, &n);
    a = (int*)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d",&tmp);
        a[i] = tmp;
    }
    qsort(a,n,sizeof(int),compare);
    i = 0;
    while(p < 200)
    {
        if(i >= n)
            break;
        p += a[i++];
        count++;
    }
    printf("%d\n",count);
}