#include<stdio.h>
#include <string.h>

int main(void)
{
    char straight[7];
    int lf = 0, rt= 0;
    scanf("%s",straight);
    int n = strlen(straight);
    for(int i = 0; i < n/2; i++)
        lf += (int)straight[i] - (int)'0';
    
    for(int i = n/2; i < n; i++)
        rt += (int)straight[i] - (int)'0';
    lf == rt ? printf("LUCKY\n") : printf("READY\n");
}