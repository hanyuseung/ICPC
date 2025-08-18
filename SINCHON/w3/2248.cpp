#include <iostream>
using namespace std;

const long long LINF = 1e18;

// f(i,j) = 길이가 i, 1의 개수가 j 인 이진수의 개수.
// 1. len = i-1, #1 = j 일때 뒤에 0 붙이기.
// 2. len = i-1, #1 = j-1 일때 뒤에 1 붙이기.

// f(i,j) = f(i-1,j) + f(i-1, j-1);


class binaryDP
{
private:
    /* data */
public:
    binaryDP(/* args */);
    ~binaryDP();
    int N,L;
    long long I;
    long long**f; // int 너무작음.

    void find();
    void makeDP();
};

void binaryDP::find(){
    makeDP();
    long long sum = 0;
    for(int i = 1; i <= N; i++){
        sum = 0;
        for(int j = 0; j<= L; j++){
            sum+= f[N-i][j];
            if(sum > LINF){ sum = LINF; break;}
        }
        if(sum >= I){
            cout << 0;
        } else{
            I -= sum;
            L--; // 허용가능 1 개수 감소
            cout << 1;
        }
    }
    cout << "\n";
}

void binaryDP::makeDP(){
    f[0][0] = 1;
    
    for(int i = 1; i <= N; i++){
        f[i][i] = f[i][0] = 1;
        for(int j = 1; j <= L; j++){
            f[i][j] = f[i-1][j] + f[i-1][j-1];
            if(f[i][j] > LINF) f[i][j] = LINF;
        }
    }
}

binaryDP::binaryDP(/* args */)
{
    cin >> N >> L >> I;
    f = new long long* [N+1];
    for (long long i = 0; i < N+1; i++)
    {
        // L까지만 했었다 그래서 메모리 초과
        f[i] = new long long [N+1];
    }
}

binaryDP::~binaryDP()
{
    for (int i = 0; i < N+1; i++){
        delete[] f[i];
    }
    delete[] f;
}

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0);                  
    cout.tie(0);
    binaryDP tmp;
    tmp.find();
    return 0;
}