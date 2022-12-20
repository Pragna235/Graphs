#include<stdio.h>
#include<stdlib.h>

int visited[8]={0};

int matrix[8][8]={
    {0,1,1,1,0,0,0,0},
    {1,0,0,0,1,0,0,0},
    {1,0,0,0,0,1,0,0},
    {1,0,0,0,0,0,1,0},
    {0,1,0,0,0,0,0,1},
    {0,0,1,0,0,0,0,1},
    {0,0,0,1,0,0,0,1},
    {0,0,0,0,1,1,1,0}

    };

 void dfs(source)
 {
     printf("%d\t",source);
     visited[source]=1;
     for(int j=0;j<8;j++)
     {
         if(matrix[source][j] == 1 && visited[j]==0)
            dfs(j);
     }
 }

 int main()
 {
     dfs(4);
     return 0;
 }

