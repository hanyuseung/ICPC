#include <iostream>
#include <vector>
#include <string>

using namespace std;

class wordladder
{
public:
    vector<string> words;
    void check();
    wordladder(/* args */);
    ~wordladder();
};

void wordladder::check()
{
    // 계속 틀렸던 이유: 종료조건에 대해 잘못 생각하고 있었음. #이 연달아 들어오면 종료라고 생각했는데,
    // 그게 아니라 words가 비어있을 때 #이 들어오면 종료인것. 즉 #이 처음에 들어오면 종료.
    string buff;

    while (1)
    {
        words.clear();
        while (cin >> buff && buff != "#")
        {
            words.push_back(buff);
        }
        if (words.empty())
            break;
        bool flag = true;

        for (int i = 1; i < words.size(); i++)
        {
            if (words[i - 1].length() != words[i].length())
            { // condition 1
                flag = false;
                break;
            }
            int inversion = 0;
            for (int j = 0; j < words[i].length(); j++)
            { // condition 2
                if (words[i][j] != words[i - 1][j])
                {
                    inversion++;
                    if (inversion > 1)
                        break;
                }
            }
            if (inversion != 1){
                flag = false;
                break;
            }
        }
        flag ? printf("Correct\n") : printf("Incorrect\n");
    }
}

wordladder::wordladder(/* args */)
{
}

wordladder::~wordladder()
{
}

int main(void)
{
    wordladder tmp;
    tmp.check();
}