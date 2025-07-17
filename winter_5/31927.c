#include <stdio.h>
#include <stdlib.h>

void print_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void copy_arr(int *arr1, int *arr2, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr2[i];
    }
}

int main(void)
{
    int n, count = 0;
    int avg = 0;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        avg += arr[i];
    }
    avg /= n;
    int **copy = (int **)malloc(sizeof(int *) * (n / 2));
    for (int i = 0; i < (n / 2); i++)
    {
        copy[i] = (int *)malloc(sizeof(int) * n);
    }

    
    int i = 0, j;
    while (i < n - 1)
    {
        while (i < n-1 && arr[i + 1] <= arr[i])
            i++;
        if(i == n-1){
            if(arr[i] >= arr[i+1]){
                break;
            }
        }
        j = i+1;
        while (j < n - 1 && arr[j] >= arr[j+1])
        {
            j++;
        }
        printf("%d %d\n",i,j);
        int mul;
        
        if (i < (j+1))
        {
            for (mul = 0; arr[i + 1] >= arr[i]; mul++)
            {
                arr[i] += avg;
            }
            arr[j+1] -= avg * mul;
            copy_arr(copy[count], arr, n);
            count++;
            if (count > (n / 2))
            {
                printf("-1\n");
                return -1;
            }
        }
        i++;
    }

    printf("%d\n", count);
    for (i = 0; i < count; i++)
        print_arr(copy[i], n);
    return 0;
}
