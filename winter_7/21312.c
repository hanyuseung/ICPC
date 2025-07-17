#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a,b,c,res;
    int taste[3];
    scanf("%d %d %d",&a,&b,&c);
    taste[0] = a*b;
    taste[1] = a*c;
    taste[2] = b*c;
    if(taste[0] % 2){
        if(taste[1] %2){
            if (taste[2]%2)
            {
                /* code */
            }
            
        }
    }
}