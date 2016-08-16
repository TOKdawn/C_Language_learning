#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#ifndef EXIT_SUCCESS 
#define EXIT_SUCCESS 0
#endif 
int main(int argc, char *argv[]) {
    int n;
    while(cin>>n){
        int max=1;
        for(int i=1;i<n;i++){
            max=++max*2;
        }
        cout<<max<<endl;
    }
    system("pause");
    return EXIT_SUCCESS;
}