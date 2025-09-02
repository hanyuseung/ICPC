#include <iostream>
#include <vector>

using namespace std;

#define FASTIO \
cin.tie(NULL); \
cout.tie(NULL); \
ios::sync_with_stdio(false);

typedef long long ll;

vector<ll> arr;
vector<ll> node;

ll build(int n, int l, int r){
    if(l == r) return node[n] = arr[l]%2; // 홀수 :1 짝수 :0. 
    int m = (l + r)/2;
    const ll lv = build(2*n, l, m);
    const ll rv = build(2*n+1, m+1, r);
    return node[n] = lv+rv;
}

ll update(int i, ll x, int n, int l, int r){
    // l == r == i?
    if(l >= i && r <= i) return node[n] = x%2; // 홀수 :1 짝수 :0. 
    if(l > i || r < i) return node[n];
    int m = (l+r)/2;
    const ll lv = update(i, x, 2*n, l, m);
    const ll rv = update(i, x, 2*n+1, m+1, r);
    return node[n] = lv+rv;
}

ll query(int qs, int qe, int n, int s, int e){
    if(qs > e || qe < s) return 0;
    if(qs <= s && qe >= e) return node[n];
    int m = (s+e)/2;
    const ll lv = query(qs, qe, 2*n, s, m);
    const ll rv = query(qs, qe, 2*n+1, m+1, e);
    return lv+rv;
}

void printnode(int n){
    for(int i = 1; i < 4*n+4; i++){
        cout << node[i]<<" ";
    }
    cout <<endl;
}

void solve(){
    int n,tmp; cin >> n;
    arr.assign(n+1,0);
    node.assign(4*n+4, 0);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    build(1,1, n);
    int m; cin >>m;
    ll a, b, c;
    for(int i =0; i< m; i++){
        cin >> a >> b >> c;
        //printnode(n);
        switch (a)
        {
        case 1:
            update(b,c,1, 1, n);
            break;
        case 2: // 짝수
            cout << (c-b+1) - query(b,c,1, 1, n)<< '\n';
            break;
        case 3: // 홀수
            cout << query(b,c,1, 1, n)<< '\n';
            break;
        default:
            break;
        }
    }
}

int main(void)
{
    FASTIO
    int t = 1;
    for(int i = 0; i < t; i++) solve();
}