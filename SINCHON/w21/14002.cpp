// Longest increasing sequence


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
    }
}

void LIS::dp(){
    int i, j;
    int max = 1;
    
    dpArr[0] = 1;
    for (i = 0; i < n; i++){
        for(j = 0; j < i; j++){
            if(array[i] > array[j] && dpArr[i] < dpArr[j] + 1){
                dpArr[i] = dpArr[j] + 1;
                prevIdx[i] = j;
                if (dpArr[i] > max){ 
                    max = dpArr[i];
                    endIdx = i;
                }
                // how to get path?

            }
        }
    }
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