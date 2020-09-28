#include <iostream>
#include <malloc.h>
#include <typeinfo>
#include <stdlib.h>

class node
{
private:
    node * next;
    int value;
public:
    node(){
        value=NULL;
    };
    node(int x){
        value=x;
    };
    ~node();
};



class NodeList
{
private:
    typedef struct nodelist{
        nodelist * next;
        int value;
    }* nodelistPtr;

    nodelist headNode;
    void recursivelyFreeNext(nodelistPtr target){
        if(!target->next){
            recursivelyFreeNext(target->next);
        }else{
            std::cout << "target:" <<target<< std::endl;
            //free(target);
            //delete [] target;
            //??????????????????????????????????????????????????????????????????????

            //how to free the memory allocated
        }
    };
public:
    NodeList(){
        std::cout << "sizeof(nodelist):" <<sizeof(nodelist)<< std::endl;
        nodelistPtr np=(nodelist*)malloc(sizeof(nodelist));
        headNode=*np;
        headNode.next=NULL;
        headNode.value=0;
        //headNode.value is the count of all values
    };
    ~NodeList(){
        nodelistPtr target = &headNode;
        for (int i = 0; i <= headNode.value; i++)
        {
            
        }
        
        getchar();
    };
    nodelistPtr findNext(nodelistPtr p){
        return p->next;
    };
    nodelistPtr LocateIndex(int index){
        //index is the position of the value in all values
        if (index<0 ||index > headNode.value)
        {
            std::cout << "Not in list" << std::endl;
            return NULL;
        }
        else
        {
            nodelistPtr target = &headNode;
            for (int i = 0; i < index; i++)
            {
                target=findNext(target);
            }
            return target;
        }      
    };
    void insert(int value,int index){
        nodelistPtr newNode = (nodelistPtr)malloc(sizeof(nodelist));
        std::cout << "newNode:" <<newNode<< std::endl;
        //nodelist *newNode = new nodelist[sizeof(nodelist)];
        //??????????????????????????????????????????????????????????????????????

        //new or malloc() ; neither can be freed in the ~NodeList()

        newNode->value=value;
        headNode.value++;
        nodelistPtr lastNode=LocateIndex(index-1); //find the front node
        newNode->next=lastNode->next;
        lastNode->next=newNode; //write in the address of new node
    };
    void deleteNode(int index){
        nodelistPtr lastNode = LocateIndex(index-1);
        nodelistPtr thisNode = lastNode->next;
        lastNode->next = thisNode->next;
        headNode.value--;
    }
    void display(){
        nodelistPtr addr = &headNode;
        std::cout << "Count:" << headNode.value <<" || "<< addr << std::endl;
        std::cout << "----------------------" << std::endl;
        for (int i = 0; i < headNode.value; i++)
        {
            addr=addr->next;
            std::cout <<"No."<<i+1<<" :"<<addr->value <<" || "<< addr << std::endl;
        }
    }
};

int main(int argc, const char** argv) {
    NodeList L;
    L.insert(1,1);
    L.insert(3,2);
    L.insert(4,1);
    L.insert(1,4);
    L.deleteNode(4);
    L.display();
   
    getchar();
    return 0;
}
