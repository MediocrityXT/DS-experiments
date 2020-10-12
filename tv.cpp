#include <iostream>
class tv
{
    
public:
    typedef struct Node{
        float price;
        int num;
        struct Node * next;
    }node,*nodePtr;
    Node * head = NULL;
    void Store(Node * head,float n,int m){
        Node * p = head;
        Node * last = NULL;
        while (p!=NULL)
        {
            if(p->price>n){
                //insert new
                Node * x = new Node();
                x->price=n;
                x->num=m;
                x->next = p;
                if(!last){
                    tv::head = x;
                    //tv is the name of this class
                }else{
                    last->next = x;
                }
                break;
            }else if(p->price == n){
                p->num += m;
                break;
            }else if(p->price<n && p->next == NULL){
                //insert new
                Node * x = new Node();
                x->price=n;
                x->num=m;
                x->next = NULL;
                p->next = x;
                break;
            }else{
                last = p;
                p=p->next;
            }
        }
        
    }
    tv(){
        nodePtr p1 =new node();
        p1->num=5;
        p1->price=1.0;
        head = p1;
        nodePtr p2 =new node();
        p2->num=6;
        p2->price=1.1;
        p1->next = p2;
    }
};
int main(int argc, const char** argv) {
    tv a;
    
    a.Store(a.head,0.9,10);
    tv::Node * p = a.head;
    while (p!=NULL)
    {
        std::cout << p->price <<",num:"<<p->num << std::endl;
        p=p->next;
    }
    
    getchar();
    return 0;
}


