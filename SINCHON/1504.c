#include <stdio.h>
#include <stdlib.h>



typedef struct node
{
    int vertex;
    int weight;
    struct node* link;
}*nodePtr;

typedef struct 
{
    int left;
    int right;
    int weight;
}edge;



/* function to make */

edge hDelete(int* size);
void hInsert(edge data ,int* size);

void gInsert();
void gFree();
int dijkstra();

/* global */
edge* heap;


int main(void)
{

}