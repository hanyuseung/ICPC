#include <stdio.h>
#include <stdlib.h>

int roof(int num, int div)
{
    if(!(num % div)){
        return num/div;
    }
    else{
        return num/div +1;
    }
}

int floorr(int num, int div)
{
    if(!(num % div)){
        return num/div -1;
    }
    else{
        return num/div;
    }
}

int main(void)
{
    int l, r, k, tmp = 0;
    scanf("%d %d %d", &l, &r, &k);
    int a,d;
    switch (k)
    {
    case 2:
        for(a = 1; r - 2*a >= 1; a++){
            tmp += (r - 2*a) - (1 >= (l -2*a) ? 1 : (l -2*a)) +1;
        }
        break;
    case 3:
        tmp = r/3 - roof(l,3) + 1;
        break;
    case 4:
        for(int d = 1; l - 3*d > 0; d++){ // 2a + 3d
            for(int i = l - 3*d; i <= r - 3*d; i++){
                tmp += i/2;
            }
        }
        break;
    case 5:
        for(d = 1 ; (r/5 - 2*a) >= 1; d++){ // 5(a+2d)
            tmp += (r/5 - 2*a) - (1 >= (roof(l, 5) - 2*d)? 1 : (roof(l, 5) - 2*d))+1;
        }
        break;
    
    default:
        break;
    }

    printf("%d\n",tmp);
}