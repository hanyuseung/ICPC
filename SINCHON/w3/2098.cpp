#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;


#define FASTIO\
ios::sync_with_stdio(false);\
cin.tie(NULL); \
cout.tie(NULL); 


typedef long long ll;

enum {UP, LEFT, DOWN, RIGHT};

void solve(){
    int n; cin >> n;
    vector<vector<int>> W (n+2, vector<int>(n+1));
    vector<vector<bool>> visited(n+2, vector<bool>(n+2));
    for(int i = 0; i <= n+1; i++){
        for(int j = 0; j <= n+1; j++){
            if(i == 0 || j == 0 || i == n + 1 || j == n + 1 ){
                W[i][j] = INT_MAX;
            } else {
                cin >> W[i][j];
                visited[i][j] = false;
            }
        }
    }
    vector<vector<vector<int>>> dp(n+2, vector<vector<int>>(n+2, vector<int>(4, 0)));
    for(int i = 0; i < 4; i++) dp[1][1][i] = W[1][1];

    
    
    // f(cur, bit) = 현재 정점이 cur, visited 가 true일때 min.
    // f(cur, bit) = min(dist(cur, next) + f(next, bit + next)).

   
    
    // f(i,j,d) 해서 d 는 direction -> 0,1,2,3 wasd
    // 구석에 박혀있거나 벽에 붙어있는 것들은 초기에 max처리
    // visited [][] 로 방문된거 재방문 안하게 처리.
}



int main(void){
    int T;
}