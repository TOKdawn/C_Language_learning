#include <iostream>
/*输入a结束*/
using namespace std;
float fun(float *s,int n){
    int i=0;
    float num=0;
    for(;i<n;i++){
        num+=s[i];
    }
    return num/(n-1);
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