#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#ifndef EXIT_SUCCESS 
#define EXIT_SUCCESS 0
#endif 
int main(int argc, char *argv[]) {
      double iBegin,iEnd;
      while(cin>>iBegin>>iEnd){
            int max1=0,max2=0;
            for(int i=iBegin;i<=iEnd;i++){
                  if(i%2){
                        max1+=i*i*i;
                  }else{
                        max2+=i*i;
                  }
            }
            cout<<max2<<" "<<max1<<endl;
      }
      system("pause");
      return EXIT_SUCCESS;
}