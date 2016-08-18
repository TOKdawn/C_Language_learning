#include <iostream>
/*输入a结束*/
using namespace std;
int GetMin(int *x,int n){
    int i=0,min=0;
    min=x[0];
    for(;i<n;i++){
        if(x[i]<min){
            min=x[i];
        }
    }
    return min;
}
int GetMax(int *x,int n){
    int i=0,min=0;
    min=x[0];
    for(;i<n;i++){
        if(x[i]>min){
            min=x[i];
        }
    }
    return min;
}
int main(int argc, char *argv[]) {
    int s[100],x,reust;
    int n=0;
    while(cin>>x){
        s[n]=x;
        n++;
    }
    reust=GetMin(s,n-1);
    cout<<"min:"<<reust;
    reust=GetMax(s,n-1);
    cout<<"max:"<<reust;
}