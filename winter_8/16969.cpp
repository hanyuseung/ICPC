#include <iostream>
#include <vector>
#include <string>

using namespace std;

class bunho
{
public:
    string type;
    long long count = 1;
    void type_checker();
    bunho(/* args */);
    ~bunho();
};

void bunho::type_checker()
{
    if(type[0] == 'd') count = 10;
    else count = 26;

    for (int i = 1; i < type.length(); i++)
    {
        if(type[i-1] == 'd'){
            if(type[i] == 'd'){
                count *= 9;
            }
            else{
                count *= 26;
            }
        }
        else{
            if(type[i] == 'd'){
                count *= 10;
            }
            else{
                count *= 25;
            }
        }
        count %= 1000000009;
    }
    cout << count;
}

bunho::bunho(/* args */)
{
    cin >> type;
}

bunho::~bunho()
{
}

int main(void)
{
    bunho tmp;
    tmp.type_checker();
}