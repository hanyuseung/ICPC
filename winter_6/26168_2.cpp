#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class search_
{
private:
    /* data */
public:
    vector<long long> A;
    search_(/* args */);
    ~search_();
    int n,m;
    long long k,i,j;
    void alloc();
    int search1();
    int search2();
    int search3();
    void print_res();
};

void search_::alloc()
{
    for (int i = 0; i < n; i++)
    {
        long long tmp;
        scanf("%lld",&tmp);
        A.push_back(tmp);
    }
}

int search_::search1()
{
    int left = 0, right = n-1;
    while (left < right)
    {
        int mid = (right + left)/2;
        if(A[mid] >= k)
            right = mid;
        else
            left = mid+1;
    }
    if(n-1 == left && k > A[left])
    {
        return 0;
    }
    else return (n - left);
}

int search_::search2()
{
    int left = 0, right = n-1;
    while (left < right)
    {
        int mid = (right + left)/2;
        if(A[mid] > k)
            right = mid;
        else
            left = mid+1;
    }
    if(n-1 == left && k >= A[left])
    {
        return 0;
    }
    else return (n - left);
}

int search_::search3()
{
    int left = 0, right = n-1;
    while (left < right)
    {
        int mid = (right + left)/2;
        if(A[mid] >= i)
            right = mid;
        else
            left = mid+1;
    }
    int l_side = left;

    if(l_side >= n || i > A[l_side])
    {
        return 0;
    }

    left = 0; right = n-1;
    while (left < right)
    {
        int mid = (right + left+1)/2;
        if(A[mid] <= j)
            left = mid;
        else
            right = mid-1;
    }
    int r_side = left;

    if (r_side < 0 || A[r_side] > j) {  
        return 0;
    }

    if (r_side < l_side) {
        return 0;
    }
    return (r_side - l_side + 1);
}

void search_::print_res()
{
    sort(A.begin(),A.end());
    int c;
    for (int I = 0; I < m; I++)
    {
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            scanf("%lld",&k);
            printf("%d\n",search1());
            break;
        case 2:
            scanf("%lld",&k);
            printf("%d\n",search2());;
            break;
        case 3:
            scanf("%lld %lld",&i,&j);
            printf("%d\n",search3());
            break;
        default:
            break;
        }
    }
}


search_::search_(/* args */)
{
    scanf("%d %d",&n,&m);
}

search_::~search_()
{
}


int main(void)
{
    search_ aa;
    aa.alloc();
    aa.print_res();
}