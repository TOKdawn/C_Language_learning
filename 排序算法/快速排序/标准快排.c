#include <stdio.h>
/*
 快排的中心思想是在一段无序数的两头开始找大于基准数或小于基准数的值并且互换,
 直到两个指针相遇,再与基准数相换,使得基准数左的数都小于它,右边都大于它.
 */
int QuickSort(int *Array,int left,int right);
int main(int argc, char const *argv[]) {
    int Array[5]={2,31,1,44,9};
    QuickSort(Array,0,4);
    for(int i=0;i<5;i++)
        printf("%d ",Array[i]);
    return 0;
}
int QuickSort(int *Array,int left,int right){
    if(left>=right){
        return 0;//结束条件,left=right,表示两个数之间没有无序的数了
    }
    int i,j,key,temp;//i左指针,j右指针,key为基准数,temp用于交换
    i=left;
    j=right;
    key=Array[left];
    while(i!=j){
        while(i<j&&key<=Array[j])
            j--;
        while (i<j&&key>=Array[i])
            i++;
        if(i<j){
            temp=Array[j];
            Array[j]=Array[i];
            Array[i]=temp;
        }
    }
    Array[left]=Array[i];
    Array[i]=key;
    QuickSort(Array,left,i-1);
    QuickSort(Array,i+1,right);
    return 0;
}
