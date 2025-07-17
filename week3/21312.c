#include <stdio.h>

int main(void)
{
    int res =1;
    int num[3];
    scanf("%d %d %d",&num[0],&num[1],&num[2]);
    int arr[3] = {num[0]%2, num[1]%2, num[2]%2};
    if(!arr[0] && !arr[1] && !arr[2]){
        printf("%d\n",num[0]*num[1]*num[2]);
        return 0;
    }
    for(int i = 0; i < 3; i++){
        if(arr[i])
            res *= num[i];
    }
    printf("%d\n",res);
}