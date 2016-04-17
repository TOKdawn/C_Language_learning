#include <stdio.h>
#include <stdlib.h>
/*冒泡排序算法的运作如下：（从后往前）

    比较相邻的元素。如果第一个比第二个大，就交换他们两个。
    对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
    针对所有的元素重复以上的步骤，除了最后一个。
    持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
*/
int pBubbingSort_Positive(int *TheArray, int Arraynum); //正向排序
int pBubbingSort_Negative(int *TheArray, int Arraynum); //反向排序
/*优化方案在于减少外层循环次数优化代码目测有问题*/
int pBubbingSort_Nice(int *TheArray, int Arraynum);
int main() {
  int Array[6] = {1, 2, 100, 5, 103, 91}; //数据以数组储存。
  pBubbingSort_Negative(Array, 6);
  for (int i = 0; i < 6; i++)
    printf("%d ", Array[i]);
  printf("\n");
  pBubbingSort_Positive(Array, 6);
  for (int i = 0; i < 6; i++)
    printf("%d ", Array[i]);
  pBubbingSort_Nice(Array, 6);
  for (int i = 0; i < 6; i++)
    printf("%d ", Array[i]);
  system("pause");
}
int pBubbingSort_Nice(int *Array, int Arraynum) {
  int j, temp, flag, k;
  flag = Arraynum;   //初始6位数都无序
  while (flag > 0) { //结束条件是前0位无序
    k = flag;        //当前前K位无序
    flag = 0;        //假设可以一次排完
    for (j = 1; j < k; j++) {
      if (Array[j] < Array[j - 1]) {
        temp = Array[j - 1];
        Array[j - 1] = Array[j];
        Array[j] = temp;
        flag = j; //如果发生交换则证明此位前无序
      }
    }
  }
  return 0;
}
int pBubbingSort_Positive(int *Array, int Arraynum) {
  int temp, i, j;
  for (i = 0; i < Arraynum; i++) {
    for (j = 1; j < Arraynum - i; j++) {
      if (Array[j] > Array[j - 1]) {
        temp = Array[j];
        Array[j] = Array[j - 1];
        Array[j - 1] = temp;
      }
    }
  }
  return 0;
}
int pBubbingSort_Negative(int *Array, int Arraynum) {
  int temp, i, j;
  for (i = 0; i < Arraynum; i++) {
    for (j = 1; j < Arraynum - i; j++) {
      if (Array[j] < Array[j - 1]) {
        temp = Array[j];
        Array[j] = Array[j - 1];
        Array[j - 1] = temp;
      }
    }
  }
  return 0;
}
