#include <stdio.h>
#include <math.h>

int main(void)
{
    int a,b,c;
    scanf("%d %d %d", &a,&b,&c);
    if(a == 0){
        int res = c*c - b;
        printf("%d\n",res);
    }
    else if(b == 0){
        int res = c*c - a;
        printf("%d\n",res);
    }
    else{
        int res = (int)sqrt((double)(a+b));
        printf("%d\n",res);
    }
    return 0;
}