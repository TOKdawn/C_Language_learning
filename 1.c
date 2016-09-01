#include <stdio.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
      int n,i,j,count,l;
      char a[100];
      scanf("%d",&i);
      for(i=0;i<n;i++){
            gets(a);
            puts(a);
            count=0;
            l=strlen(a);
            for(j=0;j<l;j++){
                  if(0<=a[j]&&a[j]<=128){
                        count++;
                  }
            }
            printf("%d",(l-count)/3);
      }
      
}