#include <stdio.h>
#include <stdlib.h>

// 일단 최소로 쪼개
int remain_bread(int x, int y, int a, int* cnt){
    int rem = a%x;
    *cnt = a/x;
    //그러고 분배해
    int diff = y-x;
    int i;
    for(i = 0; i < *cnt; i++){
        if(rem <= diff)
            return 0;
        rem = rem - diff;
    }
    return rem;
}

int main(void){
    int n,x,y,cnt,rem,a;
    int total_cnt = 0;
    int total_rem = 0;
    scanf("%d %d %d",&n,&x,&y);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        rem = remain_bread(x,y,a, &cnt);
        total_cnt += cnt;
        total_rem += rem;
    }
    printf("%d %d\n", total_cnt, total_rem);
}