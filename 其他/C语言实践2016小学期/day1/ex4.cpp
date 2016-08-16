#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#ifndef EXIT_SUCCESS 
#define EXIT_SUCCESS 0
#endif 
int lasttwo(int x){
    return x%100;
}
int main(int argc, char *argv[]) {
    double iA,iB;
    while(cin>>iA>>iB){
        iA=lasttwo(iA);
        iB=lasttwo(iB);
        
        cout<<lasttwo(iA+iB)<<endl;
    }
    system("pause");
    return EXIT_SUCCESS;
}