#include <iostream>
#include <vector>
using namespace std;

#define FASTIO \
ios::sync_with_stdio(false); \ 
cin.tie(0);                  \
cout.tie(0);

typedef long long ll;

// f(l,r) = [l, r]에서 (A - B)의 최대값.
// f(l, r) = max( A[l] - f[l+1, r] , A[r] - f[l, r-1])
// A[l,r] = ({all score = A+B} + f[1,n])/2.

int max2(int a, int b){
    return a > b? a:b;
}

void solve(){
    int n; cin >> n;
    vector <int> A(n+1);
    ll total = 0;
    vector<vector<int>> f(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++){ 
        cin>> A[i]; 
        total+=A[i];
        f[i][i] = A[i];
    }
    
    int max,l,r,len;
    
    for(len = 2; len <= n; len++){
        for(l = 1; l + len -1 <= n; l++){
            r = len + l -1;
            f[l][r] = max2(A[l] - f[l+1][r], A[r] - f[l][r-1]);
        }
    }
    
    // A+B + A-B = 2A.
    ll ct = (total + f[1][n])/2;
    cout << ct <<"\n";
}


int main(void)
{
    FASTIO
    int T; cin >> T;
    for (int i = 0; i < T; i++)
        solve();
}