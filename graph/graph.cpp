#include<iostream>
#include<malloc.h>
#include<stack>
#define Vmax 20

typedef struct EdgeNode{
    int adjVertex;  //use the index in Vertex[Vmax] to specify a Vertex
    int weight;     //for Edge Weight
    EdgeNode * next; 
}eNode;
typedef struct VertexNode{
    int data;     //Vertex data
    eNode * next; //for Edge Weight
}vNode;
typedef struct graph{  //Adjacency List
    vNode Vertex[Vmax];
    int vNum,eNum;
}MGraph;
void addEdge(MGraph &G,int Vindex,int adjVindex,int weight){
    //write in the Edges
    eNode * p = new eNode;
    p->next=NULL;
    p->weight = weight;
    p->adjVertex = adjVindex;
    G.eNum++;
    eNode * q = G.Vertex[Vindex].next;
    if(q == NULL){
        G.Vertex[Vindex].next = p;
    }else{
        while(q->next!=NULL){
            q=q->next;
        }
        q->next = p;
    }
}
void createGraph(MGraph &G){
    G.vNum = 5;
    G.eNum=0;
    for(int i = 0;i<G.vNum;i++){
        G.Vertex[i].data = i;  //or fill in any information
        G.Vertex[i].next = NULL;
    }
    addEdge(G,0,1,1);
    addEdge(G,0,3,1);
    addEdge(G,0,4,1);
    addEdge(G,1,0,1);
    addEdge(G,1,2,1);
    addEdge(G,1,3,1);
    addEdge(G,2,1,1);
    addEdge(G,2,3,1);
    addEdge(G,2,4,1);
    addEdge(G,3,0,1);
    addEdge(G,3,1,1);
    addEdge(G,3,2,1);
    addEdge(G,3,4,1);
    addEdge(G,4,0,1);
    addEdge(G,4,2,1);
    addEdge(G,4,3,1);
    std::cout << "created the G on P216" << std::endl;
}
void DFSTRaverse(MGraph &G,int v){
    // v stands for Vindex
    std::stack<int> vStack;
    int visited[Vmax] = {0};
    vStack.push(v);
    //finish initialization
    while(vStack.empty()==false){
        int target = vStack.top();
        if(visited[target]==1){
            vStack.pop();
            continue;
        }
        visited[target] = 1;
        std::cout << target << std::endl;
        //search all AdjVertex of target
        //p is the first eNode
        eNode * p = G.Vertex[target].next;
        while(p!=NULL){
            //p is any valid Node
            if(visited[p->adjVertex]==1){
                p=p->next;
            }else{
                //found a unvisited node
                vStack.push(p->adjVertex);
                break;
            }
        }
        if(p!=NULL){
            continue;
            //visit the unvisited node at the top of stack
        }
        //when there is no adjV 
        //or when p==NULL|all adjV are visited
        vStack.pop();
    }
}
void DFSTraverse(MGraph &G,int v){
    int adjMatrix [Vmax][Vmax]={0};
    // v stands for Vindex
    std::stack<int> vStack;
    int visited[Vmax] = {0};
    vStack.push(v);
    //finish initialization
    while(vStack.empty()==false){
        int target = vStack.top();
        if(visited[target]==1){
            vStack.pop();
            continue;
        }
        visited[target] = 1;
        std::cout << target << std::endl;
        //search all AdjVertex of target
        //p is the first eNode
        eNode * p = G.Vertex[target].next;
        while(p!=NULL){
            //p is any valid Node
            if(visited[p->adjVertex]==1){
                p=p->next;
            }else{
                //found a unvisited node
                vStack.push(p->adjVertex);
                adjMatrix[target][p->adjVertex]=1;
                adjMatrix[p->adjVertex][target]=1;
                break;
            }
        }
        if(p!=NULL){
            continue;
            //visit the unvisited node at the top of stack
        }
        //when there is no adjV 
        //or when p==NULL|all adjV are visited
        vStack.pop();
    }
    int edgeNum = 0;
    for(int i = 0;i<G.vNum;i++){
        for(int j = 0;j<i;j++){ //undirected Graph
            if(adjMatrix[i][j]==1){
                edgeNum++;
                std::cout << "<" <<i<<","<<j<<">"<< std::endl;
            }       
        }
    }
    std::cout << "undirectedGraph Spanning tree has " <<edgeNum<<" edges"<< std::endl;
}
/*
void Floyd(MGraph &G){
    int adjMatrix [Vmax][Vmax]={0}; 
}
*/
int main(int argc, char const *argv[])
{
    graph * p = new graph;
    MGraph G = *p;
    createGraph(G);
    DFSTraverse(G,2);
    getchar();
    return 0;
}
