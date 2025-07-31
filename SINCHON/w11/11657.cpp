// use bellman ford

#include <iostream>
#include <climits>
//#define INF 100000 : 별생각 없이 weight 슥 보고 정했는데, 너무 작게 잡았다 간선이 몇갠데

using namespace std;

typedef struct node{
    int vertex;
    int weight;
    node* link;
}*nodePtr;

class Bellmanford
{

public:
    Bellmanford(/* args */);
    ~Bellmanford();
    void insertG();
    void initG();
    int bf();
    long long* distance;
    node** graph;
    int nvert;
    int nedge;
};

Bellmanford::Bellmanford(/* args */)
{
    cin >> nvert >> nedge;
    graph = new nodePtr[nvert+1];
    distance = new long long[nvert+1];
}

Bellmanford::~Bellmanford()
{
}

void Bellmanford::initG(){
    for (int i = 0; i <= nvert; i++)
    {
        distance[i] = LLONG_MAX;
        graph[i] = NULL;
    }
    for (int i = 0; i < nedge; i++){
        insertG();
    }
}

void Bellmanford::insertG(){
    nodePtr newnd1 = new node;
    int left, right, w;
    cin >> left >> right >> w;
    
    newnd1->vertex = right; newnd1->weight = w;
    newnd1->link = graph[left];
    graph[left] = newnd1;
}

int Bellmanford::bf(){
    distance[1] = 0;
    int u,i;
    

    //실패이유 생각...
    // 1. nvert -1 번 돌아야됨
    // 2. distance가 매우 작아져서 int 범위를 벗어나는 경우? 
    //  - 작으면 갱신을 해버리니까 underflow가 발생할듯? 
    // 3. edge에 중복? 발생해도 상관없음 list니까

    // 4. 2번 해결했더니 출력초과 발생? why?
    //  - INF 가 너무 작음 많이 쌓여서 distance 좀 커졌을 때를 처리 못함.


    // 모든 edge 다볼거임. 
    for(int k = 0; k < nvert; k++){
        bool changed = false;
        for (u = 1; u <= nvert; u++){
            if(distance[u] == LLONG_MAX) continue; // 도달 불가. 스킵
            for(nodePtr nd = graph[u]; nd; nd = nd->link){
                int v = nd->vertex;
                if(distance[v] > distance[u] + nd->weight){
                    distance[v] = distance[u] + nd->weight;
                    changed = true;
                }
            }
        }
        if(!changed) break; // 갱신 없음 -> 조기종료
    }

    // negative cycle 찾기위해 모든 엣지 확인.
    for (u = 1; u <= nvert; u++){
        if(distance[u] == LLONG_MAX) continue; // 도달 불가. 스킵
        for(nodePtr nd = graph[u]; nd; nd = nd->link){
            int v= nd->vertex;
            if(distance[v] > distance[u] + nd->weight)
                return 0; // 모든 간선을 relaxation 했는데 또 됨? 이건 음이클이다.
        }
    }
    
    return 1;
}

int main (void){
    Bellmanford BMF;
    int tmp;
    BMF.initG();
    if(!BMF.bf()){
        cout<< "-1\n";
    } else{
        for (int i = 2; i <= BMF.nvert; i++)
        {
            tmp = BMF.distance[i] == LLONG_MAX ?  -1 : BMF.distance[i];
            cout << tmp <<"\n";
        }
    }

    return 0;
}