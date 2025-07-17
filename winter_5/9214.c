#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int make_int(char ch)
{
    return (((int)ch) - 48);
}

void decoding(char *code1, char *code2)
{
    int count = 0;
    int j,check = 0;
    for (j = 0; code1[j] != '\0'; j++) // decoding
    {
        if (j % 2)
        { // 1, 3 ...
            for (int k = 0; k < count; k++)
            {
                code2[check++] = code1[j];
            }
        }
        else
        { // 0, 2 ...
            count = make_int(code1[j]);
        }
    }
    code2[check] = '\0';
}

char* check_condition(char* code1, char *code2)
{
    if(strlen(code1) % 2){
        return code1;
    }
    while (1)
    {
        decoding(code1, code2);
        if(!strcmp(code1, code2)){
            return code1;
        }
        else if(strlen(code2) % 2){
            return code2;
        }
        else
            strcpy(code1, code2);
    }
    
    
}
int main(void)
{
    char code1[102];
    char code2[102];
    int i = 0;
    while (1)
    {
        i++;
        scanf("%s", code1);
        getchar();
        if (!strcmp(code1, "0\0"))
            break;
        printf("Test %d: %s\n", i, check_condition(code1, code2));
    }
}