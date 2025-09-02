#include <iostream>
#include <vector>
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

void solve(){
    int n,d; cin >> n >> d;
    ll k;
    for(int i = 0; i < n; i++){
        cin >> k;
    }
}

int main(void){
    int t = 1;
    for(int i = 0; i< t; i++) solve();
    return 0;
}
