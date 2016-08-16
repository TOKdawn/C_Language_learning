#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#ifndef EXIT_SUCCESS 
#define EXIT_SUCCESS 0
#endif 
int main(int argc, char *argv[]) {
      double iInput;
      while(cin>>iInput){
            if(iInput>100||iInput<0){
                  cout<<"SCOR IS ERROR"<<endl;
            }else if(iInput<60){
                  cout<<"E"<<endl;
            }else if(iInput<70){
                  cout<<"D"<<endl;
            }else if(iInput<80){
                  cout<<"C"<<endl;
            }else if(iInput<90){
                  cout<<"B"<<endl;
            }else {
                  cout<<"A"<<endl;
            }
      }
      system("pause");
      return EXIT_SUCCESS;
}