#include<iostream>
struct BiNode {
    int data;
    BiNode * lchild;
    BiNode * rchild;
};
void PreOrder(BiNode * root){

};
void InOrder(BiNode * root){

};
void PostOrder(BiNode * root){

};
BiNode * CreateNode(int n){
    BiNode * p = new BiNode;
    p->data = n;
    p->lchild=NULL;
    p->rchild=NULL;
};
BiNode * insertNode(BiNode * root,BiNode * node);
BiNode * CreateTree(int n){
    BiNode * root = CreateNode(1);
    root->lchild = CreateNode(2);
};
int main(int argc, char const *argv[])
{
    
    return 0;
}
