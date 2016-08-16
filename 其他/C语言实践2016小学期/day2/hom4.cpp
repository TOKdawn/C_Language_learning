#include <iostream>
/*Problem Description
输入n(n<100)个数，找出其中最小的数，将它与最前面的数交换后输出这些数
Input
输入数据有多组，每组占一行，每行的开始是一个整数n，表示这个测试实例的数值的个数，跟着就是n个整数。n=0表示输入的结束，不做处理
 Output
对于每组输入数据，输出交换后的数列，每组输出占一行。*/
using namespace std;
int main(int argc, char *argv[]) {
    int n,min,first,minnum;
    int arr[100];
    while(cin>>n){
        if(n==0){
            return 0;            
        }
        cin>>arr[0];
        min=first=arr[0];
        minnum=0;
        for(int i=1;i<n;i++){
            cin>>arr[i];
            if(arr[i]<=min){
                min=arr[i];
                minnum=i;
            }
        }
        cout<<min;
        for(int i=1;i<n;i++){
            if(i==minnum){
                cout<<first;
                continue;
            }
            cout<<arr[i];
        }
    }
}