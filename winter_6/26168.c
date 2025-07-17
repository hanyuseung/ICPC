#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void merge(long long *list, int left, int middle, int right, int n)
{
    int i = left, j = middle+1;
    int count = left;
    long long* buff = (long long*)malloc(sizeof(long long)*(n));
    memcpy(buff+left, list+left, sizeof(long long)*(right-left +1));
    while(i <= middle && j <= right)
    {
        if(buff[i] < buff[j])
        {
            list[count++] = buff[i++];
        }
        else
            list[count++] = buff[j++];
    }
    while(i <= middle)
        list[count++] = buff[i++];
    while(j <= right)
        list[count++] = buff[j++];
    free(buff);
}

void mergesort(long long *list, int left, int right, int n)
{
    if(left >= right)
    {
        return;
    }
    int middle = (left + right)/2;

    mergesort(list, left, middle, n);
    mergesort(list, middle + 1, right, n);
    merge(list, left, middle, right, n);

}

int search1(int n, long long k, long long* A)
{
    int left = -1, right = n-1;
    while (left +1 < right)
    {
        int mid = (left + right)/2;
        if(A[mid] >= k)
            right = mid;
        else
            left = mid;
    }
    return (n - right);
}

void search2(int left, int right, int k, long long* A, long long* count)
{
    if(left >= right){
        if(left == right && A[left] > k)
            (*count)++;
        return;
    }
    int mid = left + (right - left)/2;
    search2(left, mid, k, A, count);
    search2(mid+1, right, k, A, count);
}

void search3(int left, int right, int i, int j, long long* A, long long* count)
{
    if(left >= right){
        if(left == right && A[left] >=i && A[left] <= j)
            (*count)++;
        return;
    }
    int mid = left + (right - left)/2;
    search3(left, mid, i,j, A, count);
    search3(mid+1, right, i,j, A, count);
}


int main(void)
{
    int n,m;
    long long c,i,j,k;
    scanf("%d %d",&n,&m);
    long long* A = (long long*)malloc(sizeof(long long)*n);
    for (int I = 0; I < n; I++)
    {
        scanf("%lld",&A[I]);
    }
    mergesort(A, 0, n-1, n);

    for (int I = 0; I < m; I++)
    {
        scanf("%lld",&c);
        switch (c)
        {
        case 1:
            scanf("%lld",&k);
            printf("%d\n",search1(n, k, A));
            break;
        case 2:
            scanf("%lld",&k);
            //search2(0, n-1, k, A, &count);
            break;
        case 3:
            scanf("%lld %lld",&i,&j);
            //search3(0, n-1, i, j, A, &count);
            break;
        default:
            break;
        }
    }
    free(A);
}