#include <iostream>
class JonseRing
{
    
public:
    typedef struct Jonse{
        int code;
        struct Jonse * next;
    }jonse;
    
    static Jonse * Create(int n){
        Jonse * last = NULL;
        Jonse * head = NULL;
        for (int i = 0; i < n; i++)
        {
            Jonse * p = new Jonse({i,NULL});
            if(!last){
                head = p;
            }else{
                last->next = p;
            }
            last = p;
        }
        last->next = head;
        return head;
    };
    

    static void ShowList(Jonse * head){
        std::cout << "code:"<< head->code << std::endl;
        Jonse * p = head->next;
        while (p!=head)
        {
            std::cout << "code:"<<p->code << std::endl;
            p=p->next;
        }
    }

    static Jonse * JonseOut(Jonse * p,int m ,int n){
        // the arg p is the headPtr 
        // the arg n should be the number of survivals
        Jonse * head = p;
        Jonse * last = NULL;
        p=p->next;
        int count = 1;
        while (p!=head)
        {
            count++;
            p=p->next;
            if(p->next==head){
                last = p;
            }
        }
        
        for (int i = 0; i < count-n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(j == m-1){
                    last->next=p->next;
                    //delete node
                }else{
                    last = p; 
                }
                p=p->next;
            }
        }
        return p;
    }
    static void run(){
        Jonse* a = Create(30); // TOTAL NUMBER
        a = JonseOut(a,9,15); // M IS THE ARG EVERY TURN, N IS THE NUMBER OF SURVIVAL;
        ShowList(a);
        //CONTINUE debugging!
        //right output : 16 31
        
        getchar();

    }
};
int main(int argc, const char** argv) {
    JonseRing::run();
}


