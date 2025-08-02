// 1104 배껴오기
// 단 중복 엣지에 대한 최소값 처리 + digraph라는 점 유의.

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef struct node
{
    int vertex;
    int weight;
    struct node* link;
}*nodePtr;



class FloydWasher
{
public:
    FloydWasher(/* args */); // Allocation and get #v, #e
    ~FloydWasher();
    void gInsert(); // get Input grpaht
    void floydWasher();
    int getWeight(int a,int b); // 엣지 있으면 최소 weight 반환.
    void printDistance();
    int numVert, numEdge, vertA, vertB;
    nodePtr* graph;
    long long** distance;


};

void FloydWasher::printDistance(){
    for (int i = 1; i <= numVert; i++){
        for (int j = 1; j <= numVert; j++){
            long long pt = (distance[i][j] < INT_MAX) ? distance[i][j] : 0;
            cout << pt << " ";
        }
        cout << "\n";
    }
    
}

void FloydWasher::gInsert(){
    for (int i = 0; i < numEdge; i++)
    {
        int s,d,w;
        cin >> s >> d>> w;
        nodePtr nd = new node;
        nd->vertex = d;
        nd->weight = w;
        nd->link = graph[s];
        graph[s] = nd;

        // nodePtr nd2 = new node;
        // nd2->vertex = s;
        // nd2->weight = w;
        // nd2->link = graph[d];
        // graph[d] = nd2;
    }
}

int FloydWasher::getWeight(int src,int dest){
    int max = INT_MAX;
    for(nodePtr np = graph[src]; np; np = np->link){
        if(((np->vertex) == dest) && ((np->weight) < max)){
            max = np->weight;
        }
    }
    return max;
}


void FloydWasher::floydWasher(){
    int i,j,tmp;
    for (i = 0; i <= numVert; i++){
        for (j = 0; j <= numVert; j++){
            if(i == j) distance[i][j] = 0;
            else if((tmp = getWeight(i,j)) < INT_MAX) distance[i][j] = tmp;
            else distance[i][j] = INT_MAX;
        }
    }
    for (int k = 1; k <= numVert; k++)
    {
        for (int i = 1; i <= numVert; i++)
        {
            for (int j = 1; j <= numVert; j++)
            {
                distance[i][j] = distance[i][j] < distance[i][k] + distance[k][j] ? distance[i][j] : distance[i][k] + distance[k][j];
            }
        }
    }
    

}

FloydWasher::FloydWasher(/* args */)
{
    cin >> numVert;
    cin >> numEdge;
    graph = new nodePtr[numVert+1];
    distance = new long long* [numVert+1];
    for (int i = 0; i <= numVert; i++)
        distance[i] = new long long[numVert+1];
}

FloydWasher::~FloydWasher()
{
    for (int i = 0; i <= numVert; i++)
    {
        delete[] distance[i];
    }
    delete[] distance;

    for (int i = 0; i <= numVert; i++){
        for(nodePtr np = graph[i]; np;){
            nodePtr del = np;
            np = np->link;
            delete del;
        }
    }
    delete[] graph;
}



int main(void){
    FloydWasher fw;
    fw.gInsert();
    fw.floydWasher();
    fw.printDistance();
    return 0;
}