#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    int n;
    bool flag = false;
    scanf("%d",&n);
    int *x = (int*)malloc(sizeof(int)*n);
    int *y = (int*)malloc(sizeof(int)*n);
    char *c = (char*)malloc(sizeof(char)*n);
    for (int i = 0; i < n; i++)
        scanf("%d",&x[i]);
    for (int i = 0; i < n; i++)
        scanf("%d",&y[i]);
    for (int i = 0; i < n; i++)
        scanf(" %c",&c[i]);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
             if(((x[i] - x[j]) <= y[i]+y[j]) && (c[i] != c[j]))
             {
                printf("YES\n");
                printf("%d %d\n",j+1,i+1);
                flag = true;
                break;
             }
        }
        if(flag)
            break;
    }
    if(!flag)
        printf("NO\n");
}