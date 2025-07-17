#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int main(void)
{
    int n,i = 1,j = 0;
    scanf("%d",&n);
    char string[50000];
    scanf("%s",string);
    n =strlen(string);
    
    int* left = (int*)calloc(n+1, sizeof(int));
    int* right = (int*)malloc(sizeof(int)*(n+1));
    for(;i < n; i++){
        if(string[i] =='(' && string[i-1] == '('){
            left[i] = 1;
        } 
    }
    right[n-1] = 0;
    for(i = n-1; i > 0; i--){
        if(string[i] == ')' && string[i-1] == ')'){
            right[i-1] = right[i] + 1; // count...
        }else{
            right[i-1] = right[i];
        }
    }
    int result = 0;
    for(i = 1;i <n; i++){
        if(left[i])
            result += right[i+1];
    }
    printf("%d\n", result);
}