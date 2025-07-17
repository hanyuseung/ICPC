#include <iostream>
#include <vector>
#include <string>
using namespace std;

class palin
{
public:
    palin(/* args */);
    ~palin();
    vector<string> strs;
    int n;
    int count {0};//palindrome 개수
    void count_pal();
    void print_pal();
};

palin::palin(/* args */)
{
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        strs.push_back(tmp);
    }
}


void palin::count_pal()
{
    for(int i = 0; i < n; i++){
        int len = strs[i].length();
        count++;
        for(int j = 0; j < len/2; j++)
        {
            if(strs[i][j] != strs[i][len -j -1]){
                count --;
                break;
            }
        }
    }
}

void palin::print_pal(){
    cout << count*(count -1)<<"\n";
}

palin::~palin()
{
}

int main(void)
{
     palin tmp;
     tmp.count_pal();
     tmp.print_pal();
}