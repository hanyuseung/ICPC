#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int *top = (int *)malloc(sizeof(int) * (n));
    for (int i = 0; i < n; i++)
        scanf("%d", &top[i]);
    int max = top[0];//1
    for (int i = 1; i < n - 1; i++)//2
    {
        if (top[i - 1] == 0 || top[i] == 0 || top[i + 1] == 0)
            continue;
        else{
            int current = top[i] + (top[i - 1] < top[i + 1] ? top[i - 1] : top[i + 1]);
            if (max < current)
                max = current;
        }
    }
    if(max < top[n-1])//3
        max = top[n-1];
    printf("%d\n", max);
}