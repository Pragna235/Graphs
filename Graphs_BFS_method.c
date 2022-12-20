#include<stdio.h>
#include<stdbool.h>
#define N 8

int queue[N];
int vertex;
int front=-1, rear=-1;
//int vertex;
int visited[8]={0};
int matrix[N][N]={
    {0,1,1,1,0,0,0,0},
    {1,0,0,0,1,0,0,0},
    {1,0,0,0,0,1,0,0},
    {1,0,0,0,0,0,1,0},
    {0,1,0,0,0,0,0,1},
    {0,0,1,0,0,0,0,1},
    {0,0,0,1,0,0,0,1},
    {0,0,0,0,1,1,1,0}


};

void enqueue(int x)
{
    if(rear==N-1)
        printf("Queue is Full!");
    else if(rear==-1 && front==-1)
    {
        //printf("Queue is Empty!");
        rear=front=0;
        queue[rear]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}

int dequeue()
{
    int h;
    if(front==-1 && rear==-1)
        //printf("Queue is Empty!");
        h=0;
    else if(rear==front)
    {
        h=queue[front];
        rear=front=-1;
    }
    else
    {
        h=queue[front];
        front++;

    }
    return h;

}

bool isempty()
{
    if(front==-1 && rear==-1)
        return true;
    else
    return false;
}



int main()
{
    int source=0;
    printf("%d\t",source);
    visited[source]=1;
    enqueue(source);
    while(!isempty()){
        vertex=dequeue();
        for(int j=0;j<8;j++){
            if(matrix[vertex][j]==1&& visited[j]==0){
                printf("%d\t",j);
                visited[j]=1;
                enqueue(j);
            }

        }
    }
    return 0;
}

