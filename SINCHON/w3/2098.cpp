#include <iostream>
#include <vector>

using namespace std;

#define FASTIO\
ios::sync_with_stdio(false);\
cin.tie(NULL); \
cout.tie(NULL); 


typedef long long ll;

void solve(){
    int n; cin >> n;
    vector<vector<int>> W (n+1, vector<int>(n+1));
    vector<vector<bool>> visited(n+1, vector<bool>(n+1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> W[i][j];
            visited[i][j] = false;
        }
    }
   vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(4)));
   


    
    // f(i,j,d) 해서 d 는 direction -> 0,1,2,3 상하좌우 하고
    // 구석에 박혀있거나 벽에 붙어있는 것들은 초기에 max처리
    // visited [][] 로 방문된거 재방문 안하게 처리.
}



int main(void){
    int T;
}