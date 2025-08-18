// Longest Increasing Subsequence


/******* dp ************
 * i. 1일때 0
 * 
 */
#include <iostream>
#include <stack>
using namespace std;

class LIS
{
public:
    LIS(/* args */);
    ~LIS();
    void getInput();
    void dp();
    void ptPath();
    
    int n;
    int* array;
    int* dpArr;
    int* prevIdx;
    int endIdx = 0;
};

void LIS::getInput(){
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
        prevIdx[i] = -1;
        dpArr[i] = 1;// init by 1... 만약 단조 감소 수열이면 어디든 1이자너
    }
}

void LIS::dp(){
    int i, j;
    int max = 1;

    for (i = 0; i < n; i++){
        for(j = 0; j < i; j++){
            if(array[i] > array[j] && dpArr[i] < dpArr[j] + 1){
                dpArr[i] = dpArr[j] + 1;
                prevIdx[i] = j;
                if (dpArr[i] > max){ 
                    max = dpArr[i];
                    endIdx = i;
                }
            }
        }
    }
    

    /*
    counter example
    13
    3 4 5 6 2 3 1 7 4 3 5 6 7

    34567로 출력. 원인은?
     -> dp 테이블을 initialize 를 안했으니까... 바보임?
    */

    cout << max << "\n";
}

void LIS::ptPath(){
    int i = endIdx,j;
    stack<int> st;
    while(i!=-1){
        st.push(i);
        i = prevIdx[i];
    }
    while(!st.empty()){
        cout << array[st.top()] <<" ";
        st.pop();
    }
    cout << "\n";
}

LIS::LIS(/* args */)
{
    cin >> n;
    array = new int[n+1];
    dpArr = new int [n+1];
    prevIdx = new int [n+1];
}

LIS::~LIS()
{
    delete[] array;
    delete[] dpArr;
    delete[] prevIdx;
}

int main(void){
    LIS a;
    a.getInput();
    a.dp();
    a.ptPath();
    return 0;
}   