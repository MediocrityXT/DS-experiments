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
        nodePtr target = L;
        //headNode need to be free as well
        while(target!=NULL)
        {
            nodePtr p=target->next;
            std::cout << "freed  " <<target<< std::endl;
            free(target);
            target=p;
        }
        
        getchar();
    };
    nodePtr ListPointer(){
        return L;
    }
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
        //start from the first node
        nodePtr thisNode=L->next;
        nodePtr nextNode;
        
        for (int i = 0; i < L->data ; i++)
        {
            nextNode=thisNode->next;
            if(i==0){
                L->next=NULL;
            }
            //update L->next to the last node
            thisNode->next=L->next;
            L->next=thisNode;
            //no need to change L->data
            thisNode=nextNode;
        }
        
    }
    void unionList(nodePtr la,nodePtr lb){
        nodePtr preA = la;
        nodePtr pb = lb->next;
        //merge lb into la
        int sum = la->data+lb->data;
        while (la->data!=sum)
        {
            //comparing on pa and pb two Nodes
            nodePtr pa = preA->next;
            if(pa!=NULL && pb!=NULL){
                if(pa->data >= pb->data){
                    nodePtr breakpoint =pb->next;
                    //insert pb in front of pa
                    preA->next=pb;
                    pb->next=pa;

                    preA=preA->next;
                    pb=breakpoint;
                }else{
                    //moving pa
                    preA=preA->next;
                }
            }else{
                if(!pa){
                    //put rest of lb after la
                    preA->next=pb;
                    la->data=sum;
                    lb->next=NULL;
                }
                if(!pb){
                    //finish
                    la->data=sum;
                    lb->next=NULL;
                }
            }
        }
        
    }
    void display(){
        nodePtr addr = L;
        std::cout << "Count:" << L->data <<" || "<< addr <<"\n"<< std::endl;
        for (int i = 0; i < L->data; i++)
        {
            addr=addr->next;
            std::cout <<"No."<<i+1<<" :"<<addr->data <<" || "<< addr << std::endl;
        }
        std::cout << "----------------------" << std::endl;
    }
};

int main(int argc, const char** argv) {
    NodeList L;
    L.insert(1,1);
    L.insert(3,2);
    L.insert(4,3);
    L.insert(4,4);
    L.insert(6,5);
    L.insert(7,6);
    L.display();
    L.reverse();
    L.display();
    /*
    NodeList B;
    B.insert(1,1);
    B.insert(2,2);
    B.insert(5,3);
    B.display();
    L.unionList(B.ListPointer(),L.ListPointer());
    B.display();
   */
    getchar();
    return 0;
}
