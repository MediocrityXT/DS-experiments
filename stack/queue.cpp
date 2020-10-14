#include <iostream>
class queue
{
    
public:
    typedef struct Node{
        int code;
        struct Node * next;
    }node;
    
    Node * rear;
    
    Node * Create(int n){
        Node * last = NULL;
        Node * head = NULL;
        for (int i = 0; i < n; i++)
        {
            Node * p = new Node({i,NULL});
            if(!last){
                head = p;
            }else{
                last->next = p;
            }
            last = p;
        }
        last->next = head;
        rear = last;
        return head;
    };
    
    void Enqueue(Node * &rear, int x){
    	if(rear == NULL){
    		Node * p = new Node;
    		p->code = x;
    		p->next = p;
    		rear = p;
		}else{
			Node * p = new Node;
    		p->code = x;
    		p->next = rear->next;
    		rear->next = p;
    		rear = p;
		}
	}
	void Dequeue(Node * &rear){
		if(rear == NULL){
			std::cout<<"Queue is Empty"<<std::endl;
		}
		else if(rear->next==rear){
			delete rear->next;
			rear = NULL;
		}
		else{
			Node * target = rear->next;
			rear->next = target->next;
			delete target;
		}
	}

    void ShowList(Node * head){
        std::cout << "code:"<< head->code << std::endl;
        Node * p = head->next;
        while (p!=head)
        {
            std::cout << "code:"<<p->code << std::endl;
            p=p->next;
        }
    }
};
int main(int argc, const char** argv) {
    queue a;
	a.Create(5); // TOTAL NUMBER
	a.Enqueue(a.rear,8);
	a.Enqueue(a.rear,9);
	a.Dequeue(a.rear);
	a.Enqueue(a.rear,7);
    a.ShowList(a.rear->next);
    
    getchar();
}
