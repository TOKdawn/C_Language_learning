#include <iostream>
using namespace std;
int main(int argc, char *argv[]) {
    int n,m,x;
    int a[100];
    while(cin>>n>>m){
        if(n==m&&n==0){
            return 0;
        }
        for(int i;i<=n;i++){
            cin>>x;
            if(m<=x){                
                a[i]=m;
                i++;
            }
            a[i]=x;
        }
        for(int i;i<=n;i++){
            cout<<a[i];
        }
    }
    return 0;
}