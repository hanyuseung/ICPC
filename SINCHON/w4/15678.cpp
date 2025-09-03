#include <iostream>
#include <vector>
#include <limits.h>
#define FASTIO \
cin.tie(NULL); \
cout.tie(NULL); \
ios::sync_with_stdio(false);

using namespace std;

typedef long long ll;

/************** ********
 * 일단 dp문제임
 * 재방문 불가, D 칸 만큼 떨어진 곳을 방문 가능.
 * 이때 합을 최대화 -- dp
 * 
 * 그러면 어떻게하지?
 * 1. 처음 발판이 i
 * 2. i 이전에 j를 밟았음.
 * D[i] = max(a_i, (max D[j] {j : i - D ~ i 까지.}+ a_i))
 * i-D ~ i 까지중 최대인 D[j] 구하기 -> D[i]를 x로 업데이트
*/

vector <ll> node;
vector <ll> arr;
vector <ll> D;

ll max2(ll a, ll b){
    return a > b ? a:b;
}


ll update(int i, ll x, int n, int l, int r){
    if(l >= i && r <= i) return node[n] = x;
    if(l > i || r < i) return node[n];
    int m = (l + r)/2;
    const ll lval = update(i, x, 2*n, l, m);
    const ll rval = update(i, x, 2*n+1, m+1, r);
    return node[n] = max2(lval, rval);
}

ll query(int qs, int qe, int n, int s, int e){
    if (e < qs || qe < s) return LONG_LONG_MIN;
    if (qs <= s && e <= qe) return node[n];

    int m = (s+e)/2;
    const ll lval = query(qs, qe, 2*n, s, m);
    const ll rval = query(qs, qe, 2*n+1, m+1, e);
    return max2(lval, rval);
}




void solve(){
    int n,d; cin >> n >> d;
    arr.assign(n+1, 0);
    D.assign(n+1,LONG_LONG_MIN);
    node.assign(4*n+4, LONG_LONG_MIN);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    D[1] = arr[1];
    update(1, D[1], 1, 1, n);
    // dp
    ll maxn = D[1];
    for(int i = 2; i <= n; i++){
        // d가 얼마일지 모르니까
        int left = max(1, i - d), right = i-1;

        ll best = LONG_LONG_MIN;
        if(left <= right) best = query(left, right , 1,1,n);

        if(best == LONG_LONG_MIN) D[i] = arr[i];
        else D[i] = max2(arr[i], best + arr[i]);

        update(i, D[i], 1, 1, n);
        if(maxn < D[i]) maxn = D[i];
    }
    cout << maxn << "\n";
}

int main(void){
    FASTIO
    int t = 1;
    for(int i = 0; i< t; i++) solve();
    return 0;
}
