#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n, c = 0, ow = 0, res;
    scanf("%d",&n);
    char *str = (char*)malloc(sizeof(int)*(n+2));
    scanf("%s",str);
    for (int i = 0; i <n; i++)
    {
        if(str[i] == 'C'){
            c++;
        } else{
            ow++;
        }
    } // ow+1 개의 토막으로 자르자
    if(c%++ow){
        res = c/ow +1;
    } else{
        res = c/ow;
    }
    printf("%d\n",res);
}