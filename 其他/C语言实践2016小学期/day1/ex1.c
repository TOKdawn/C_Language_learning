#include <stdio.h>
#include <stdlib.h>
#ifndef EXIT_SUCCESS 
#define EXIT_SUCCESS 0
#endif 

int main(int argc, char *argv[]) {
      int iInput;
      while(~scanf("%d",&iInput)){
            system("cls");
            for(int i=1;i<=iInput;i++){
                  for(int j=1;j<=i;j++){
                        printf("%d",i);
                  }
                  printf("\n");
            }
      }
      system("pause");
      return EXIT_SUCCESS;
}