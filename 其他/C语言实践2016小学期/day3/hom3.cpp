#include <iostream>
/*输入a结束*/
using namespace std;
int fun(float *s,int n){
    int i=0,numl=0;
    float num=0;
    float ptr;
    for(;i<n;i++){
        num+=s[i];
    }
    ptr=num/(n-1);
    for(i=0;i<n;i++){
        if(s[i]<ptr)
            numl++;
    }
    return numl-1;
}
int main(int argc, char *argv[]) {
    float s[100],x,reust;
    int n=0;
    while(cin>>x){
        s[n]=x;
        n++;
    }
    reust=fun(s,n+1);
    cout<<reust;
}