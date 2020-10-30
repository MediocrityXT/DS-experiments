#include<iostream>
#include<malloc.h>
#include<stack>
#define Vmax 20
class Graph{
};

typedef struct graph{
    int vNum,eNum;
    int Vertex[Vmax];  //for Vertex data
    int AdjMatrix[Vmax][Vmax]; //for Edge Weight
}MGraph;
void createGraph(MGraph G,int n){
    G.vNum = n;
    for(int i = 0;i<Vmax;i++){
        if(i<n){
            //write data of Vertex
            G.Vertex[i] = 1;
        }else{
            G.Vertex[i] = 0;
        }
        for(int j = 0;j<Vmax;j++){
            G.AdjMatrix[i][j]=0;
        }
    }
    G.eNum=0;
    //write data of Edge
    for(int i = 0;i<n-1;i++){
        G.AdjMatrix[i][i+1]=1;
        G.AdjMatrix[i+1][i]=1;
        G.eNum+=1;
        //undirected graph
    }
    
    printf("created a G");
}
void DFSTRaverse(MGraph G,int v){
    std::stack<int> vStack;
    vStack.push(v);
    int visited[G.vNum] = {0};
    while(vStack.empty()==false){
        int target = vStack.top();
        //searchAd(target);
    }
}
int main(int argc, char const *argv[])
{
    MGraph * a=(MGraph *)malloc(sizeof(MGraph));
    createGraph(*a,10);
    return 0;
}
