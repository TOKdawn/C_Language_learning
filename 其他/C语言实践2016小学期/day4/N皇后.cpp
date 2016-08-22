#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define SUCCESS 1
#define FAIL 0
using namespace std;
void print(int** arr,int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<arr[i][j]<<endl;
        }
    }
}
int test(int** arr,int n,int i,int j){
    int k;
    for(k=0;k<i;k++){
        if(arr[k][j]==1||
           (k-i+j>=0&&arr[k][k-i+j]==1)||
           (i+j-k<n&&arr[k][i+j-k]==1))
           return FAIL;
    }
    return SUCCESS;
}
void Queen(int n){
    int** arr;
    int i,j;
    int count=0;
    Stack* s;
    InitStack(s);
    if(n<4){
        cout<<"n不能小于4"<<endl;
        return ;
    }
    arr=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++){
        arr[i]=(int*)malloc(n*sizeof(int));
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    i=0,j=0;
    for(j=0;j<n;j++){
        if(test(arr, n, i, j)){
            arr[i][j]=1;
            Push(s,j);
            i++;
        }else{
            j++;
            continue;
        }
        if(j==n||i==n){
            if(i==n){
                print(arr, n);
                cout<<endl;
                i--; 
            }    
            if(i<0){
                //free;
                return;
            }else{
                j=Pop(s);
                arr[i][j]=0;
                j++;
                continue;
                }
        }else{
            j=0;
            continue;
        }
         
    }    
}
int main(int argc, char *argv[]) {
    Queen(4);
}