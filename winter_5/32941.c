#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    int t,x,k,n;
    
    bool res_flag = true;
    scanf("%d %d", &t, &x);
    scanf("%d",&n);
    int **list = (int**)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        scanf("%d",&k);
        list[i] = (int*)malloc(sizeof(int)*k);
        for(int j = 0; j < k; j++){
            scanf("%d",&list[i][j]);
            if(x == list[i][j])
                flag = true;
        }
        if(!flag)
            res_flag = false;
    }

    if(res_flag){
        printf("YES\n");
    }
    else
        printf("NO\n");
}