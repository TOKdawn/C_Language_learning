#include <stdio.h>
void x2(int ***);
void x1(int **);
void x(int *);
void x2(int ***p) {
  printf("Now in func x2.   p(&p1)==%p\n", p);
  x1(*p);
  return;
}
void x1(int **p1) {
  printf("Now in func x1.   p1(&p2)==%p\n", p1);
  x(*p1);
  return;
}
void x(int *p2) {
  printf("Now in func x.   p2(&a)==%p\n", p2);
  *p2 = 8;
  return;
}
int main(int argc, char *argv[]) {
  int ***p;
  int **p1;
  int *p2;
  int a = 10;
  p2 = &a;
  p1 = &p2;
  p = &p1;
  printf("&p==%p\n&p1==%p\n&p2==%p\n&a==%p\n", &p, &p1, &p2, &a);
  x2(p);
  printf("%d", a);
}
