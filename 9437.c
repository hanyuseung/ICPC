#include <stdio.h>
#include <stdlib.h>

int main(void){
    int a,b;
    while(1)
    {
        scanf("%d",&a);
        if(!a) return 0;
        scanf("%d",&b);

        int x,y,z;
        if(b>(a/2)){
            if(b%2){// odd
                y = a +1 - b;
                x = a - b;
                z = b+1;
            }else{
                x = a + 1 - b;
                y = a - b + 2;
                z = b-1;
            }
        }else{
            if(b%2){// odd
                z = a +1 - b;
                y = a - b;
                x = b+1;
            }else{
                y = a + 1 - b;
                z = a - b + 2;
                x = b-1;
            }
        }
        printf("%d %d %d\n", x,y,z);
    }
}