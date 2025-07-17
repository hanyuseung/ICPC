#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m, part;
    scanf("%d",&n);
    int *arr;
    arr = malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&m);
        if(m >= 300)
            part = 1;
        else if(m >=275)
            part = 2;
        else if(m >= 250)
            part = 3;
        else
            part = 4;

        arr[i] = part;
    }
    for(int i = 0; i < n; i++)
        printf("%d ",arr[i]);
    printf("\n");
    free(arr);
    return 0;
}