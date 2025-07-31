#include <stdio.h>
#include <stdlib.h>

#define INF 1010

typedef struct node
{
    int vertex;
    int weight;
    struct node* link;
}*nodePtr;

typedef struct{
    int vertex;
    int distance;
}heapNode;


/* function to make */

heapNode hDelete(int* size);
void hInsert(heapNode new ,int* size);
void hAdjust(int vertex, int newDist);

void gInit();
void gInsert();
void gFree();
int dijkstra();

/* global */
heapNode* heap;
int* hPos;
nodePtr* graph;
int* distance;
int* visited;
int numVert, numEdge;
int source, dest;


void hInsert(heapNode new ,int* size){
    int i = ++(*size);
    while(i > 1 && new.distance < heap[i/2].distance){
        heap[i] = heap[i/2]; 
        hPos[heap[i].vertex] = i;
        i/=2;
    }

    heap[i] = new;
    hPos[heap[i].vertex] = i;
}

heapNode hDelete(int* size){
    heapNode ret = heap[1];
    heapNode last = heap[(*size)--];

    int parent = 1;
    int child;
    while(parent*2 <= (*size)){
        child = parent*2;
        if(child < (*size) && heap[parent*2].distance > heap[parent*2+1].distance)
            child++;
        if(last.distance <= heap[child].distance) break;
        heap[parent] = heap[child];
        parent = child;
        hPos[heap[parent].vertex] = parent;
    }
    
    heap[parent] = last;
    hPos[heap[parent].vertex] = parent;

    hPos[ret.vertex] = 0;
    return ret;
}

void hAdjust(int vertex, int newDist){
    int i = hPos[vertex];
    if (newDist >= heap[i].distance) return; // 더 작아야 의미 있음

    heap[i].distance = newDist;

    // 부모보다 작으면 계속 올린다
    while (i > 1 && heap[i].distance < heap[i / 2].distance) {
        // swap(heap[i], heap[i/2])
        heapNode tmp = heap[i / 2];
        heap[i / 2] = heap[i];
        heap[i] = tmp;

        // 위치 배열도 함께 갱신
        hPos[heap[i].vertex] = i;
        hPos[heap[i / 2].vertex] = i / 2;

        i /= 2;
    }
}

void gInsert(){
    int left, right, weight;
    scanf("%d %d %d", &left,&right,&weight);
    nodePtr newNode = (nodePtr)malloc(sizeof(struct node));
    newNode->vertex = right;
    newNode->weight = weight;
    newNode->link = graph[left];
    graph[left] = newNode;

    nodePtr newNode2 = (nodePtr)malloc(sizeof(struct node));
    newNode2->vertex = left;
    newNode2->weight = weight;
    newNode2->link = graph[right];
    graph[right] = newNode2;
}

void gInit(){
    scanf("%d %d",&numVert, &numEdge);
    graph = (nodePtr*)malloc(sizeof(nodePtr)*(numVert+1));
    visited = (int*)calloc((numVert+1), (sizeof(int)));
    heap = (heapNode*)malloc(sizeof(heapNode)*(numVert + 1));
    hPos = (int*)calloc((numVert+1), (sizeof(int)));
    distance = (int*)malloc(sizeof(int)*(numVert+1));
    for (int i = 0; i < numVert+1; i++){
        distance[i] = INF;
        graph[i] = NULL;
    }
    for (int i = 0; i < numEdge; i++)
        gInsert();

    scanf("%d %d",&source, &dest);
}

int dijkstra(){
    /*  1. source와 그 인접 distance 갱신
        2. dest가 visited 될때 까지 
            heap에서 pop - visited 하고 distance 갱신
    */
    int size = 0;
    distance[source] = 0;
    heapNode start = {source, 0};
    hInsert(start, &size);
    
    
    while(size > 0){
        heapNode popedge = hDelete(&size);
        int v = popedge.vertex;
        if(visited[v]) continue;
        visited[v] = 1;

        if(v == dest) break;
        
        for(nodePtr tmpnode = graph[v]; tmpnode; tmpnode = tmpnode->link){
            int w = tmpnode->vertex;
            int newDistance = distance[v] + tmpnode->weight;
            if(newDistance < distance[w]) {
                distance[w] = newDistance;
                if(!hPos[w]){ // PQ에 없다
                   heapNode nd = {w, newDistance};
                   hInsert(nd, &size); // Insert
                } else hAdjust(w, newDistance); // decrease key
            }
        }
    }

    return distance[dest];
}

int main(void)
{
    gInit();
    int dis = dijkstra();
    if(dis != INF) printf("%d\n",dis);
    else printf("-1\n");
    return 0;
}