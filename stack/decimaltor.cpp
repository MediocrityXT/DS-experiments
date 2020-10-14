#include<iostream>
#include<math.h>

void Decimaltor(int num,int r){
    int m = num%r;
    int n = num/r;
    if(n == 0){
        std::cout<<m;
    }else{
        Decimaltor(n,r);
        std::cout<<m;
    }
}
int main(int argc, char const *argv[])
{
    Decimaltor(27,3);
    getchar();
    return 0;
}
