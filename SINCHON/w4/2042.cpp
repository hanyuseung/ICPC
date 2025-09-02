#include <iostream>
#include <vector>
using namespace std;

#define FASTIO \
ios::sync_with_stdio(false);\
cin.tie(NULL); \
cout.tie(NULL); 


typedef long long ll;
/********* 구간합 구하기 *******
 * 점 업데이트: 수열의 i번째 합을 X로 업데이트
 * 선분 합: 수열의 s번째부터 e번째까지의 합을 구함
 * */


// 현재 노드 n. 구간 left, right.

vector <ll> node; // 합트리
vector <ll> arr; // 입력배열

// 합트리 구성.
ll build(int n, int left, int right){
    if(left == right) return node[n] = arr[left];
    int mid = (left+right) /2 ;
    ll l = build(2*n, left, mid);
    ll r = build(2*n+1, mid +1, right);
    return node[n] = l + r;
}


// update는 node 자체를 변화
// 아 ll ㅅㅂ
ll update(ll i, ll x, int n, int left, int right) {
    if(left > i || i > right) return node[n]; // 무관
    if(left == right) return node[n] = x; // 1칸
    // 하급자에게 전달
    const int mid = (left+right)/2;
    const ll lval = update(i, x, 2*n , left , mid);
    const ll rval = update(i, x, 2*n+1, mid+1, right);
    return node[n] = lval + rval;
}

// 쿼리는 구간 합이나 값을 물어보기 (s: start, e: end).
ll query(int qs, int qe, int n, int s, int e) {
    if (e < qs || qe < s) return 0;
    if (qs <= s && e <= qe) return node[n];
    const int m = (s + e) / 2;
    const ll lval = query(qs, qe, 2*n , s, m); // 아오 ll
    const ll rval = query(qs, qe, 2*n+1, m+1, e);
    return lval + rval;
}



void solve(){
    int n,m,k; cin >> n >> m >> k;

    arr.assign(n+1, 0);
    node.assign(4*n+4, 0);

    for (int i = 1; i <= n; i++) cin >> arr[i]; 
        
    build(1,1,n);
    ll a,b,c;
    for (int i = 0; i < m+k; i++){
        cin >> a >> b >> c;
        if (a == 1){
            update(b, c, 1, 1, n);
        } else if(a == 2){
            cout << query(b, c, 1, 1, n) << "\n";
        }
    } 
}


int main(void)
{
    FASTIO
    solve();
}