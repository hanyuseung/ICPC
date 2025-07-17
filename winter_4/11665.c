#include <stdio.h>
#include <stdlib.h>

typedef struct dot
{
    int x;
    int y;
    int z;
}dot;

typedef struct Cube{
    dot p;
    dot q;
}Cube;


int volume(Cube* cube, int N)
{
    Cube tmp = cube[0];
    for (int i = 0; i < N-1; i++)
    {
        //x
        if(cube[i].p.x <= cube[i+1].p.x && cube[i+1].q.x <= cube[i].q.x)
        {
            tmp.p.x = cube[i+1].p.x;
            tmp.q.x = cube[i+1].q.x;
        }
        else if(cube[i+1].p.x <= cube[i].p.x && cube[i].q.x <= cube[i+1].q.x)
        {
            tmp.p.x = cube[i].p.x;
            tmp.q.x = cube[i].q.x;
        }
        else if(cube[i+1].p.x < cube[i].p.x && cube[i+1].q.x < cube[i].q.x)
        {
            if(cube[i].p.x < cube[i+1].q.x){
                tmp.p.x = cube[i].p.x;
                tmp.q.x = cube[i+1].q.x;
            }
            else{
                return 0;
            }
        }
        else if(cube[i].p.x < cube[i+1].p.x && cube[i].q.x < cube[i+1].q.x)
        {
            if(cube[i+1].p.x < cube[i].q.x){
                tmp.p.x = cube[i+1].p.x;
                tmp.q.x = cube[i].q.x;
            }
            else{
                return 0;
            }
        }

        //y
        if(cube[i].p.y <= cube[i+1].p.y && cube[i+1].q.y <= cube[i].q.y)
        {
            tmp.p.y = cube[i+1].p.y;
            tmp.q.y = cube[i+1].q.y;
        }
        else if(cube[i+1].p.y <= cube[i].p.y && cube[i].q.y <= cube[i+1].q.y)
        {
            tmp.p.y = cube[i].p.y;
            tmp.q.y = cube[i].q.y;
        }
        else if(cube[i+1].p.y < cube[i].p.y && cube[i+1].q.y < cube[i].q.y)
        {
            if(cube[i].p.y < cube[i+1].q.y){
                tmp.p.y = cube[i].p.y;
                tmp.q.y = cube[i+1].q.y;
            }
            else{
                return 0;
            }
        }
        else if(cube[i].p.y < cube[i+1].p.y && cube[i].q.y < cube[i+1].q.y)
        {
            if(cube[i+1].p.y < cube[i].q.y){
                tmp.p.y = cube[i+1].p.y;
                tmp.q.y = cube[i].q.y;
            }
            else{
                return 0;
            }
        }

        //z
        if(cube[i].p.z <= cube[i+1].p.z && cube[i+1].q.z <= cube[i].q.z)
        {
            tmp.p.z = cube[i+1].p.z;
            tmp.q.z = cube[i+1].q.z;
        }
        else if(cube[i+1].p.z <= cube[i].p.z && cube[i].q.z <= cube[i+1].q.z)
        {
            tmp.p.z = cube[i].p.z;
            tmp.q.z = cube[i].q.z;
        }
        else if(cube[i+1].p.z < cube[i].p.z && cube[i+1].q.z < cube[i].q.z)
        {
            if(cube[i].p.z < cube[i+1].q.z){
                tmp.p.z = cube[i].p.z;
                tmp.q.z = cube[i+1].q.z;
            }
            else{
                return 0;
            }
        }
        else if(cube[i].p.z < cube[i+1].p.z && cube[i].q.z < cube[i+1].q.z)
        {
            if(cube[i+1].p.z < cube[i].q.z){
                tmp.p.z = cube[i+1].p.z;
                tmp.q.z = cube[i].q.z;
            }
            else{
                return 0;
            }
        }
        cube[i+1] = tmp;
    }
    return ((tmp.q.x - tmp.p.x)*(tmp.q.y - tmp.p.y)*(tmp.q.z - tmp.p.z));
}

int main(void)
{
    int N;
    scanf("%d",&N);
    Cube* cube = (Cube*)malloc(sizeof(Cube)*N);
    for (int i = 0; i < N; i++)
    {
        int x1,y1,z1, x2,y2,z2;
        scanf("%d %d %d %d %d %d",&x1,&y1,&z1, &x2,&y2,&z2);
        cube[i].p.x = x1; cube[i].q.x = x2;
        cube[i].p.y = y1; cube[i].q.y = y2;
        cube[i].p.z = z1; cube[i].q.z = z2;
    }
    printf("%d\n",volume(cube, N));

}