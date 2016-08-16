#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
int main(int argc, char *argv[]) {
    char a;
    int n;
    cin>>n;
    for(int j=0;j<n;j++){
        for(int i=0;i<5;i++){
            cin>>a;
        }
        for(int i=0;i<6;i++){
            cin>>a;
            cout<<a;
        }
    }
    return EXIT_SUCCESS;
}