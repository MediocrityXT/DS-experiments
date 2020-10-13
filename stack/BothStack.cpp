#include <iostream>
#define STACKSIZE 100
class Bothstack{
public:
    typedef struct BothStack{
        int data[STACKSIZE];
        int top1;
        int top2;
    }BothStack;
    void InitBothStack(BothStack S){
        S.top1 = -1;
        S.top2 = STACKSIZE;
    }

    void PushBothStack(BothStack S,int i,int intnumber){

    }
    int PopBothStack(BothStack S,int i){
        
    }
};
int main(int argc, const char** argv) {
    return 0;
}