#include <stdio.h>
#include <stdlib.h>

// Just sorting with reverse.


void reverse(int a, int b, int *card)
{
    while (a < b)
    {
        int tmp = card[a];
        card[a] = card[b];
        card[b] = tmp;
        a++; b--;
    }
}

int main(void)
{
    //처음에 stack에 trace를 넣어 출력하려 했는데, 생각해보니 stack에 넣으면 반대로 출력됨...
    //그러면 queue에 넣어야 하는데 귀찮아서 그냥 두번계산
    int N,i,j, count = 0;

    scanf("%d",&N);
    int* card = (int*)malloc(sizeof(int)*N);
    int* card2 = (int*)malloc(sizeof(int)*N);

    for (i = 0; i < N; i++){
        scanf("%d",&card[i]);
        card2[i] = card[i];
    }
    

    for (i = 0; i < N; i++){
        for(j = i; j < N; j++){
            if(card[j] == i+1){
                break;
            }
        }
        if(i != j){
            reverse(i,j, card);
            count++;
        }
    }
    free(card);
    printf("%d\n",count);

    for (i = 0; i < N; i++){
        for(j = i; j < N; j++){
            if(card2[j] == i+1){
                break;
            }
        }
        if(i != j){
            reverse(i,j, card2);
            printf("%d %d\n",i+1 ,j+1);
        }
    }
    free(card2);
}

