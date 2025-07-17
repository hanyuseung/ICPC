#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int k,s;
    scanf("%d %d",&k, &s);
    getchar();
    k %= 26;
    char* str;
    str = (char*)malloc(sizeof(char)*(s+2));
    scanf("%[^\n]",str);
    for (int i = 0; i < s; i++)
    {
        int asc = (int)str[i];
        if((asc >= 65) && (asc <= 90))
        {
            int enc = asc + k;
            if(enc > 90){
               enc = 64 + enc - 90;
            }
            str[i] = (char)enc;
        }
        else if((asc >= 97) && (asc <= 122))
        {
            int enc = asc + k;
            if(enc > 122){
               enc = 96 + enc - 122;
            }
            str[i] = (char)enc;
        }
    }
    printf("%s\n",str);
    free(str);
}