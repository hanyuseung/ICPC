#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parsing(char* str, char** strs)
{
    int i = 0;
    const char *delim = " ";
    char* token = strtok(str, delim);
    while(token != NULL){
        strs[i++] = token;
        token = strtok(NULL, delim);
    }
    return i;
}

int main(void)
{
    int n,cnt = 0;
    scanf("%d",&n);
    getchar();
    char str[102];
    char res[102];
    char* strs[52];

    for(int i = 0; i <n; i++){
        if(!fgets(str,sizeof(str),stdin)) break;
        str[strcspn(str, "\n")] = '\0';
        cnt = parsing(str, strs);
        strcpy(res,"god");
        for(int i = 1 ; i < cnt; i++)
            strcat(res,strs[i]);
        printf("%s\n",res);
    }
    return 0;
}
