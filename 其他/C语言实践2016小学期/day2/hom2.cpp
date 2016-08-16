#include <iostream>

using namespace std;
void get(){
    char x;
    while(cin>>x){
        get();    
        cout<<x;
        return;
    }
    return;
}
int main(int argc, char *argv[]) {
    get();
}