#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#ifndef EXIT_SUCCESS 
#define EXIT_SUCCESS 0
#endif 
int main(int argc, char *argv[]) {
    double n,x,y,num=0,i=0;
    int max,min;
    cin>>x>>y;
    if(x<y){
        max=y,min=x;
    }else{
        max=x,min=y;
    }
    while(cin>>n){//结束条件怎么判断?不以字符串读取的话如何检测出输入流结束?\n应该直接被吞了
        i++;
        if(n<min){
            num+=min;
            min=n;
        }else if(n>max){
            num+=max;
            max=n;
        }else{
            num+=n;
        }
    }
    cout<<num/i<<endl;
    system("pause");
    return EXIT_SUCCESS;
}