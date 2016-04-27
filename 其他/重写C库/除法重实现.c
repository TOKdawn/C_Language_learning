#include <stdio.h>
//#define TURE 1
int divisionII(int, int);
double divisionID(int, double);
double divisionDI(double, int);
double divisionDD(double, double);
double square(int x) { //处理小数位,
  double y = 0.1;
  for (int i = 1; i < x; i++) {
    y *= 0.1;
  }
  return y;
}
int main(int argc, char const *argv[]) {
  double a;
  double b, c;
  scanf("%lf%lf", &a, &b);
  c = divisionDD(a, b);
  printf(" C=%lf,my=%lf", a / b, c);
  return 0;
}
int divisionII(int x, int y) {
  int sum;
  while ((x -= y) >= 0) { //基本思想就是看x中有多少个y
    sum++;
  }
  return sum;
}
double divisionID(int a, double y) {
  double x = (double)a; //都强转为浮点数防止精度丢失
  double intnum = 0, floatnum = 1, sum = 0;
  if (x > y) {
    intnum = 1;
    while ((x -= y) >= y)
      intnum++;
  }                //处理整数部分
  while (x != 0) { //整除是一种退出
    floatnum = 1;
    for (; x < y; sum++) { // sum用于记录当前在小数点后多少位
      x = x * 10;          //应对需要多次进位的情况
    }
    while ((x -= y) >= y) {
      floatnum++; //借位后道理跟整数一样
    }
    intnum = intnum + square(sum) * floatnum;
    if (x == 0 || sum == 8) //退出条件,精度达到8或者整除;
      break;
  }
  return intnum;
}
double divisionDI(double x, int a) {
  double y = (double)a;
  double intnum = 0, floatnum = 1, sum = 0;
  if (x > y) {
    intnum = 1;
    while ((x -= y) >= y)
      intnum++;
  }
  while (x != 0) {
    floatnum = 1;
    for (; x < y; sum++) {
      x = x * 10;
    }
    while ((x -= y) >= y) {
      floatnum++;
    }
    intnum = intnum + square(sum) * floatnum;
    if (x == 0 || sum == 8)
      break;
  }
  return intnum;
}
double divisionDD(double x, double y) {
  double intnum = 0, floatnum = 1, sum = 0;
  if (x > y) {
    intnum = 1;
    while ((x -= y) >= y)
      intnum++;
  }
  while (x != 0) {
    floatnum = 1;
    for (; x < y; sum++) {
      x = x * 10;
    }
    while ((x -= y) >= y) {
      floatnum++;
    }
    intnum = intnum + square(sum) * floatnum;
    if (x == 0 || sum == 8)
      break;
  }
  return intnum;
}
