#include <stdio.h>
#include <string.h>
int main(void)
{
    int a,b;
    char c[101];
    scanf("%d %d %s",&a,&b, c);
    int last = c[strlen(c)-1] - '0';
    if(last%2)printf("%d\n", a^b);
    else printf("%d\n", a);
}
