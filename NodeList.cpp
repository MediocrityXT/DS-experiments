#include <iostream>
#include <malloc.h>
#include <typeinfo>
#include <stdlib.h>

class NodeList
{
private:
    typedef struct node{
        int data;
        node * next;
    }* nodePtr ,** LinkList;
    //What is the meaning of LinkList?

    nodePtr L;
    //L is the head pointer
    nodePtr createNode(){
        nodePtr headNode=(node*)malloc(sizeof(node));
        headNode->next=NULL;
        headNode->data=0;
        return headNode;
    }
    nodePtr createNode(int x){
        nodePtr newNode=(node*)malloc(sizeof(node));
        newNode->next=NULL;
        newNode->data=x;
        L->data++;
        return newNode;    
    }
public:
    NodeList(){
        L= createNode();
        //automatically create a list with a headNode
    };
    ~NodeList(){
        nodePtr target = L->next;
        while(target!=NULL)
        {
            nodePtr p=target->next;
            std::cout << "freed  " <<target<< std::endl;
            free(target);
            target=p;
        }
        
        getchar();
    };
    
    nodePtr LocateValue(int value){
        nodePtr p=L->next;
        int cnt=0;
        while (p!=NULL)
        {
            cnt++;
            if(p->data == value){
                std::cout <<value << " position at: " <<cnt<< std::endl;
                return p;
            }
            p=p->next;
        }
        std::cout << "MISSING Value" << std::endl;
        return NULL;
    };
    nodePtr LocatePos(int pos){
        //pos is the position of the data in all datas
        if (pos < 0 ||pos > L->data)
        {
            std::cout << "Not in list" << std::endl;
            return NULL;
        }
        else
        {
            nodePtr target = L;
            for (int i = 0; i < pos; i++)
            {
                target=target->next;
            }
            return target;
        }      
    };
    void insert(int data,int pos){
        nodePtr newNode=createNode(data);      
        nodePtr lastNode=LocatePos(pos-1); //find the front node
        newNode->next=lastNode->next;
        lastNode->next=newNode; //write in the address of new node
    };
    void deleteNode(int pos){
        nodePtr lastNode = LocatePos(pos-1);
        nodePtr thisNode = lastNode->next;
        lastNode->next = thisNode->next;
        free(thisNode);
        L->data--;
    };
    void reverse(){
        nodePtr newL=L;

        //start from the first node
        nodePtr thisNode=L->next;
        nodePtr nextNode;
        
        for (int i = 0; i < L->data ; i++)
        {
            nextNode=thisNode->next;
            if(i==0){
                L->next=NULL;
            }
            //insert
            thisNode->next=L->next;
            L->next=thisNode;
            //no need to change L->data
            thisNode=nextNode;
        }
        
    }
    void unionList(nodePtr la,nodePtr lb){
        nodePtr pa = la;
        nodePtr pb = lb;
        //merge lb into la
        int sum = la->data+lb->data;
        while (la->data!=sum)
        {
            //working on pa->next and pb->next two Nodes
            if(pa->next!=NULL && pb->next!=NULL){
                if(pa->next->data >= pb->next->data){

                }else{
                    
                }
            }
        }
        
    }
    void display(){
        nodePtr addr = L;
        std::cout << "Count:" << L->data <<" || "<< addr << std::endl;
        std::cout << "----------------------" << std::endl;
        for (int i = 0; i < L->data; i++)
        {
            addr=addr->next;
            std::cout <<"No."<<i+1<<" :"<<addr->data <<" || "<< addr << std::endl;
        }
    }
};

int main(int argc, const char** argv) {
    NodeList L;
    L.insert(1,1);
    L.insert(3,2);
    L.insert(4,1);
    L.insert(5,4);
    L.insert(6,5);
    L.insert(7,6);

    L.deleteNode(1);
    NodeList B = L;
    //L.LocateValue(2);
    L.reverse();
    NodeList U;
    L.display();
   
    getchar();
    return 0;
}
