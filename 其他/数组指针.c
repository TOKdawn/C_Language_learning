#include <stdio.h>
#define Arrynum 10
typedef int (*_p)[Arrynum];
//建立数组指针并且通过函数赋值
int x(_p p) {
  for (int i = 0; i < Arrynum; i++) {
    (*p)[i] = 8;
  }
  return 0;
}
int main(int argc, char *argv[]) {
  int a[Arrynum] = {0};
  _p p;
  p = &a;
  x(p);
  for (int i = 0; i < Arrynum; i++)
    printf("%d ", a[i]);
}
/*二维数组版本
#include <stdio.h>
#define Arrynum 10
typedef int (*_p)[Arrynum][Arrynum];
int x(_p p){
      for(int i=0;i<Arrynum;i++){
            for(int j=0;j<Arrynum;j++)
                  (*p)[i][j]=8;
      }
      return 0;
}
int main(int argc, char *argv[]) {
      int a[Arrynum][Arrynum]={0};
      _p p;
      p=&a;
      x(p);
      for(int i=0;i<Arrynum;i++){
            for(int j=0;j<Arrynum;j++)
                  printf("%d ",a[i][j]);
      }
}

*/
