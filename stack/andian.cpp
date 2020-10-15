#include<iostream>
void Andian(int A[][3],int M,int N){
    for(int i=0;i<N;i++){
        int min=A[i][0];
        int min_j=0;
        for(int j =0;j<M;j++){
            if(A[i][j]<min){
                min = A[i][j];
                min_j=j;
            }
        }
        bool flag = true;
        //compare j colomn;
        for(int x=0;x<N;x++){
            if(A[x][min_j]>min){
                flag =  false;
                break;
            }
        }
        if(flag){
            std::cout << min << std::endl;
        }
    }
}
int main(int argc, char const *argv[])
{
    int A[3][3]={1,2,3,2,3,4,1,1,1};//??
    //int A [4][4] = {9,7,6,8,  20 , 26 , 22 , 25,28 , 36  ,25  ,30,12 ,  4 ,  2 ,  6};
    Andian(A,3,3);
    return 0;
}
