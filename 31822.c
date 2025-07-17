#include <stdio.h>
int main(void){
    int n, count = 0;
    char strings[16][20];
    char str[20];
    scanf("%s",str);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s",strings[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5;j++){
            if(str[j] == strings[i][j]){
                if(j == 4) count++;
            }
            else break;
        }
    }
    printf("%d\n",count);
}