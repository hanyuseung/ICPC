#include <iostream>
#include <algorithm>
#include <queue>

#define INF  1010
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
    int getWeight(int a,int b); // 엣지 있으면 weight 반환.

    int numVert, numEdge, vertA, vertB;
    //int* heapPos;
    nodePtr* graph;
    //int* visited;  
    int** distance;

    //priority_queue<heapNode> pq;
};

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

        nodePtr nd2 = new node;
        nd2->vertex = s;
        nd2->weight = w;
        nd2->link = graph[d];
        graph[d] = nd2;
    }
    cin >> vertA >> vertB;
}

int FloydWasher::getWeight(int src,int dest){
    for(nodePtr np = graph[src]; np; np = np->link){
        if((np->vertex) == dest){
            return np->weight;
        }
    }
    return 0;
}


void FloydWasher::floydWasher(){
    int i,j,tmp;
    for (i = 0; i <= numVert; i++){
        for (j = 0; j <= numVert; j++){
            if(i == j) distance[i][j] = 0;
            else if((tmp = getWeight(i,j)) != 0) distance[i][j] = tmp;
            else distance[i][j] = INF;
        }
    }
    for (int k = 1; k < numVert; k++)
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
    cin >> numVert >> numEdge;
    graph = new nodePtr[numVert+1];
    //heapPos = new int [numVert+1];
    //visited = new int [numVert+1];
    distance = new int* [numVert+1];
    for (int i = 0; i <= numVert; i++)
        distance[i] = new int[numVert+1];
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
    // 1 - a - b - N, 1 - b - a - N
    cout << fw.distance[1][fw.vertA] << " ";
    cout << fw.distance[fw.vertA][fw.vertB]<< " ";
    cout << fw.distance[fw.vertB][fw.numVert] <<endl;
    return 0;
}