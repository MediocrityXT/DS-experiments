#include <iostream>
#define STACKSIZE 100
class Bothstack{
public:
    typedef struct BothStack{
        int data[STACKSIZE];
        int top1;
        int top2;
    }BothStack;
    BothStack S;
    void InitBothStack(BothStack &S){//& for argument
        //参数有形参（parameter）和实参（argument）
        S.top1 = -1;
        S.top2 = STACKSIZE;
    }

    void PushBothStack(BothStack &S,int i,int intnumber){
        // i : 1 or 2
        if(S.top1 +1 ==S.top2){
            //full stack
            std::cout << "StackOverFlow" << std::endl;
            return;
        }
        if(i==1){
            if(S.top1<STACKSIZE-1){
                S.top1++;
                S.data[S.top1]=intnumber;
            }else{
                std::cout << "Stack 1 is FULL" << std::endl;
            }
        }
        else if(i==2){
            if(S.top2>0){
                S.top2--;
                S.data[S.top2]=intnumber;
            }else{
                std::cout << "Stack 2 is FULL" << std::endl;
            }
        }
        else{
            std::cout << "ChooseWrongStack" << std::endl;
        }
    }
    int PopBothStack(BothStack &S,int i){
        if(i==1){
            if(S.top1>-1){
                int res=S.data[S.top1];
                S.top1--;
                return res;
            }else{
                std::cout << "Stack 1 is EMPTY" << std::endl;
            }
        }
        else if(i==2){
            if(S.top2<STACKSIZE){
                int res=S.data[S.top2];
                S.top2++;
                return res;
            }else{
                std::cout << "Stack 2 is EMPTY" << std::endl;
            }
        }
        else{
            std::cout << "ChooseWrongStack" << std::endl;
        }
    }
};
int main(int argc, const char** argv) {
    Bothstack s;
    s.InitBothStack(s.S);
    s.PushBothStack(s.S,1,3);
    s.PushBothStack(s.S,1,5);
    s.PushBothStack(s.S,2,6);
    std::cout << s.PopBothStack(s.S,1) << std::endl;
    std::cout << s.PopBothStack(s.S,2) << std::endl;
    s.PushBothStack(s.S,1,2);
    std::cout << s.PopBothStack(s.S,1) << std::endl;
    
    getchar();
    return 0;
}