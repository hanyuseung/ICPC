#include <iostream>
#include <vector>
#define FASTIO \
cin.tie(NULL); \
cout.tie(NULL); \
ios::sync_with_stdio(false);


using namespace std;

typedef long long ll;

vector<ll> node;
vector<ll> arr;

const long long MOD = 1000000007LL;


ll build(int n, int left, int right){
    if(left == right) return node[n] = arr[left];
    int m = (left + right)/2;
    const ll lval = build(2*n, left, m);
    const ll rval = build(2*n+1, m+1, right);

    return node[n] = (lval * rval)%MOD;
}

ll update(int idx, ll x, int n, int lf, int rt){
    if(lf > idx || rt < idx) return node[n];
    if(lf == rt) return node[n] = x;

    int mid = (lf + rt)/2;
    const ll lval = update(idx, x, 2*n, lf, mid);
    const ll rval = update(idx, x, 2*n+1, mid+1, rt);
    return node[n] = (lval*rval)%MOD;
}

ll query(int qs, int qe, int n, int s, int e){
    if (e < qs || qe < s) return 1;
    if (qs <= s && e <= qe) return node[n];

    int m = (s+e)/2;
    const ll l = query(qs, qe, 2*n, s, m);
    const ll r = query(qs, qe, 2*n+1, m+1, e);
    return (l*r)%MOD;
}


// void printnode(int n){
//     for(int i = 1; i < 4*n+4; i++){
//         cout << node[i]<<" ";
//     }
//     cout <<endl;
// }


void solve(){
    int n,m,k; cin >> n >> m >> k;
    arr.assign(n+1,0);
    node.assign(4*n + 4, 0);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    build(1,1,n);

    ll a,b,c;
    for(int i = 0; i < m+k; i++) {
        cin >> a >> b >> c;
        if(a == 1){
            update(b,c, 1, 1, n);
        } else if(a == 2){
           cout << query(b,c, 1, 1, n) << "\n";
        }
    }
}

int main(void)
{
    int t=1;
    for(int i = 0; i < t; i++) solve();
}