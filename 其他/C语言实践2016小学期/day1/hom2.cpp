#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
int main(int argc, char *argv[]) {
    string line;
    bool x=1;
    while(getline(cin,line)){
        x=1;
        if(line[0]<='A'||line[0]>='z'||('Z'<line[0]&&line[0]<'a')){
            x=0;
            if(line[0]=='_')
                x=1;
        }
        if(!x)
            goto end;
        for(int i=0;i<line.length();i++){
            if(line[i]<='A'||line[i]>='z'||('Z'<line[i]&&line[i]<'a')){
                x=0;
                if(line[i]=='_')
                    x=1;
                if('0'<=line[i]&&line[i]<='9')
                    x=1;
            }
        }
        if(!x)
            goto end;
end:     if(!x){
            cout<<"no"<<endl;
        }else{
            cout<<"yes"<<endl;
        }
    }

    system("pause");
    return EXIT_SUCCESS;
}