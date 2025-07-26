#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, left, right, diff;
    scanf("%d", &n);
    int* gravel = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&gravel[i]);
    }
    left = gravel[0];
    right = gravel[1];

    for(int i = 2; i< n; i++){
        if(left == right){
            left += gravel[i];
        }else if(left < right){
            left += gravel[i];
        } else{
            right += gravel[i];
        }
    }

    if(left == right) {
        printf("0\n");
        return 0;
    } 
    else {
        diff= (left < right) ? (right - left) : (left - right);
        int weight[7] = {100, 50, 20 ,10, 5, 2, 1};
        int cnt =0;

        for(int i =0 ; i< 7; i++){
            cnt += diff/ weight[i];
            diff %= weight[i];
            if(diff == 0) break;
        }

        printf("%d\n",cnt);
        
    }
    free(gravel);
    return 0;

    
}