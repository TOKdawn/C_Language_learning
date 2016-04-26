#include <stdio.h>
char *func() {
  char x[100];
  char *k;
  scanf("%s", x);
  k = (char *)malloc(strlen(x) + 1);
  strcpy(k, x);
  return k;
}
int main(int argc, char *argv[]) {
  char *a;
  a = func();
  return 0;
} //节省空间,申请的空间全部用来储存数据,如果用char
  //a[100]而就储存两个字符就会出现内存浪费;
