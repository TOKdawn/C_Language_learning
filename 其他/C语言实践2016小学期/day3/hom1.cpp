#include <iostream>
using namespace std;
void get(int n){
    char x;
    cin>>x;
    if (n==6){
        return;
    }else{
        get(++n);
        cout<<x;
        return ;
    }
}

int main(int argc, char *argv[]) {
    get(1);
}