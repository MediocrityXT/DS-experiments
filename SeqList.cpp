#include <iostream>
#include <malloc.h>
#include <typeinfo>
#include <stdlib.h>
#define MAXNUM 10
using namespace std;

typedef struct SeqList
{
    int * elem; //address of value
    int length; //number of elems
}seq,*seqPtr;
void init(seqPtr s){
    s->elem=(int *)malloc(MAXNUM*sizeof(int));
    s->length=0;
    if(!s->elem)cout<<"error!\ns->elem:"<<s->elem<<endl;
};
int CheckValue(seqPtr s,int value){
    for (int i = 0; i < s->length; i++)
    {
        if(s->elem[i]==value){
            return i+1; //location = index + 1
        }
    }
    std::cout << "no value matched" << std::endl;
    return -1;
};
int CheckLocation(seqPtr s,int location){
    //location = index + 1
    if(location<= s->length && location > 0)
        return s->elem[location-1];
    else
    {
        std::cout << "no such location in list" << std::endl;
        return -1;
    }
};
void insert(seqPtr s,int value,int index){
    //index: index of new value after the insertion
    if((index >= 0 && index <= s->length)&&(s->length<MAXNUM)){
        for(int i = s->length;i > index;i--){
            s->elem[i]=s->elem[i-1];
        }
        s->elem[index]=value;
        s->length++;    
    }
    else//if index is invalid or overflow
    {
        std::cout << "insert error" << std::endl;
    }   
};
void insertBySequence(seqPtr s,int x){
    //L is sequential by default
    int index = -1;

    for (int i = 1; i < s->length ; i++)
    {
        if(x <= s->elem[i]){
            index = i;
            break;
        }
    }
    
    if(x > s->elem[s->length - 1])index = s->length;
    //index: index of new value after the insertion
    if((index >= 0 && index <= s->length)&&(s->length<MAXNUM)){
        for(int i = s->length;i > index;i--){
            s->elem[i]=s->elem[i-1];
        }
        s->elem[index]=x;
        s->length++;    
    }
    else//if index is invalid or overflow
    {
        std::cout << "insert error" << std::endl;
    }   
};
void deleteData(seqPtr s,int index){
    //check if index of the object value is valid
    if(index >= 0 && index < s->length){
        for (int i = index; i <= s->length; i++)
        {
            s->elem[i]=s->elem[i+1];
        }
        s->length--;
    }else{
        std::cout << "object not in list" << std::endl;
    }
};
void loadData(seqPtr s){ //fill some default values
    for(int i = 0;i < 4;i++){
        s->elem[i]=rand();
        s->length++;
    }
};
void print(seqPtr s){
    if(s->length == 0) std::cout << "EMPTY LIST!" << std::endl;
    for (int i = 0; i < s->length; i++)
    {
        std::cout << s->elem[i] << " |addr: "<<&s->elem[i] << std::endl;
    }
    std::cout <<"--- List END ---\n" << std::endl;
};
void destroy(seqPtr s){
    free(s->elem);
    //option:set elem to null
    s->elem=NULL;
    s->length=0;
};
void Reverse(seqPtr s){
    int upperBound=(s->length)/2;
    for (int i = 0; i < upperBound; i++)
    {
        int temp = s->elem[i];
        s->elem[i] = s->elem[s->length-1 - i] ;
        s->elem[s->length-1 - i] = temp;
    }
};
void ReverseList(seq L){
    //operation of *elem is on the original memory block,so L is the same as pointer s.
    //this func can't change L.length in main
    int upperBound=(L.length)/2;
    for (int i = 0; i < upperBound; i++)
    {
        int temp = L.elem[i];
        L.elem[i] = L.elem[L.length-1 - i] ;
        L.elem[L.length-1 - i] = temp;
    }
};
void Interest(seqPtr A,seqPtr B,seqPtr C){
    // C is a empty list with size limit

    for (int i = 0; i < A->length; i++)
    {
        for (int j = 0; j < B->length; j++)
        {
            if(A->elem[i]==B->elem[j]){
                C->elem[C->length]=A->elem[i];
                C->length++;
                break;
            }
        }        
    }    
};

void Union(seqPtr A,seqPtr B,seqPtr C){
    // C is a empty list with size limit

    // copy A to C
    for (int i = 0; i < A->length; i++)
    {
        C->elem[i]=A->elem[i];
        C->length++;
    }
        
    for (int i = 0; i < B->length; i++)
    {
        if(C->length == MAXNUM){
            std::cout << "Union is too large!" << std::endl;
            break;
        }
        for (int j = 0; j < A->length; j++)
        {   
            
            if(B->elem[i]==A->elem[j]){
                break;//next B->elem
            }
            if(j == A->length - 1){
                //B->elem[i] is different from any elem in A
                C->elem[C->length]=B->elem[i];
                C->length++;
            }
        }        
    }    
}
int main(int argc, const char** argv) {
    seq L; 
    seqPtr s=&L;//declare the seqList with the pointer s
    init(s);
    loadData(s);
    print(s);
    //std::cout << "the location of value 1 is : " << CheckValue(s,1) << std::endl;
    //std::cout << "the value from location 4 is :" << CheckLocation(s,4) << std::endl;
    //insert(s,232,2);
    //deleteData(s,2);
    //Reverse(s);
    //insertBySequence(s,3);
    seq A,C;
    seqPtr a=&A;
    seqPtr c=&C;
    init(a);
    //take s as b
    init(c);
    loadData(a);
    insert(a,41,3);
    print(a);
    print(c);
    //finish the initiation
    Interest(s,a,c);
    print(c);
    destroy(s);
    destroy(a);
    destroy(c);
    getchar();
        //linux version of system("pause")
    return 0;
}
