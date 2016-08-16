#include <stdio.h>

int QuickSort(int *Array,int left,int right);
int main(int argc, char const *argv[]) {
    int Array[1000];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&Array[i]);
    }
    QuickSort(Array,0,n-1);
    for(int i=0;i<5;i++)
        printf("%d ",Array[i]);
    return 0;
}
int QuickSort(int *Array,int left,int right){
    if(left>=right){
        return 0;
    }
    int i,j,key,temp;
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