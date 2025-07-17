#include <iostream>
#include <algorithm>
using namespace std;

// knapsack: sort - dptable

class Ims
{
public:
    int p,n, result;
    int** dp;
    int* a;
    Ims();
    ~Ims();
    
    void inp();
    void DP();
};

Ims::Ims(/* args */)
{
    result = 0;
    cin >> p >> n;
}

Ims::~Ims()
{
    for (int i = 0; i < n; i++)
    {
        free(dp[i]);
    }
    free(dp);
    free(a);
}

void Ims::inp()
{
    dp = (int**)malloc(sizeof(int*)*n);
    a = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++){
        dp[i] = (int*)calloc(p,sizeof(int));
        cin >> a[i];
    } 
}

void Ims::DP()
{
    int i,j;
    sort(a, a + n);

    for(i=1; i < n; i++)
    {
        for(j = 0; j < p; j++)
        {
            if((j - a[i]) < 0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = (dp[i-1][j - a[i]] + 1) > dp[i-1][j] ? dp[i-1][j - a[i]] + 1 : dp[i-1][j];
            
            if(result < dp[i][j])
                result = dp[i][j];
        }
    }
    cout<<result<<"\n";
}

int main(void)
{
    Ims tmp;
    tmp.inp();
    tmp.DP();
}



