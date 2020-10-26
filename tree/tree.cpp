#include<iostream>
#include<queue>
#include<malloc.h>
struct BiNode {
    int data;
    BiNode * lchild;
    BiNode * rchild;
};

BiNode * CreateNode(int n){
    BiNode * p = new BiNode;
    p->data = n;
    p->lchild=NULL;
    p->rchild=NULL;
};
void insertNode(BiNode * father,BiNode * lchild,BiNode * rchild){
    father->lchild=lchild;
    father->rchild=rchild;
};


void PreOrder(BiNode * root){
    if(root!=NULL){
        std::cout << root->data<<" ";
        PreOrder(root->lchild);
        PreOrder(root->rchild);
        return;
    }
};
void InOrder(BiNode * root){
    if(root!=NULL){
        InOrder(root->lchild);
        std::cout << root->data<<" ";
        InOrder(root->rchild);
        return;
    }
};
void PostOrder(BiNode * root){
    if(root!=NULL){
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        std::cout << root->data<<" ";
        return;
    }
};
void LevelOrder(BiNode * root){
    //no recursion here
    std::queue<BiNode *> queue; // <> stands for the elem type in queue
    queue.push(root);
    while(!queue.empty()){
        BiNode * root = queue.front();
        if(root!=0){
            queue.push(root->lchild);
            queue.push(root->rchild);
            std::cout << root->data<<" ";
            queue.pop();
        }
    }
};
int CountLeaf(BiNode * root){
    if(root!=NULL){
        if(root->lchild==NULL && root->rchild==NULL){
            //leaf node
            return 1;
        }
        return CountLeaf(root->lchild)+CountLeaf(root->rchild);
    }
    return 0; //father's vain child and father has another real child 
}
int CountBiNode(BiNode * root){
    if(root!=NULL){
        return CountBiNode(root->lchild)+CountBiNode(root->rchild)+1;
    }
    return 0; //father's vain child and father has another real child 
}
int Depth(BiNode * root){
    if(root!=NULL){
        return std::max(Depth(root->lchild),Depth(root->rchild))+1;
    }
    return 0; //father's vain child and father has another real child 
}
void Exchange(BiNode * root){
    if(root!=NULL){
        //std::cout << root->data << std::endl;
        Exchange(root->lchild);
        Exchange(root->rchild);
        BiNode * temp =root->lchild;
        root->lchild=root->rchild;
        root->rchild=temp;   
    }
}
void InsertBST(BiNode * root,BiNode * s){
    //compare s->data with root
    if(root->data==s->data){
        return;
    }else{
        if(s->data<root->data){
            if(root->lchild==NULL){
                root->lchild=s;
            }else{
                InsertBST(root->lchild,s);
            }
        }else{
            if(root->rchild==NULL){
                root->rchild=s;
            }else{
                InsertBST(root->rchild,s);
            }
        }           
    }
}
BiNode * CreateTree(){
    int r[10] ={78,54,82,37,65,23,45,87,85,94};
    BiNode * root;
    BiNode ** nodeList = (BiNode **)malloc(10*sizeof(BiNode *));
    nodeList[0] = CreateNode(r[0]);
    for(int i=1;i<10;i++){
        nodeList[i] = CreateNode(r[i]);
        InsertBST(nodeList[0],nodeList[i]);
    }
    return nodeList[0];
};
int main(int argc, char const *argv[])
{
    BiNode * tree = CreateTree();
    InOrder(tree);
    getchar();
    return 0;
}
