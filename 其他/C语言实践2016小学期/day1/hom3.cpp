#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
int main(int argc, char *argv[]) {
    string line;
    int num;
    while(getline(cin,line)){
        num=0;
        for(int i=0;i<line.length();i++){
            if('0'<=line[i]&&line[i]<='9')
            num++;
        }
        cout<<num<<endl;
        
    }
    system("pause");
    return EXIT_SUCCESS;
}