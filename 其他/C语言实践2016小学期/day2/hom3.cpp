#include <iostream>
/*Problem Description
对于输入的每个字符串，查找其中的最大字母，在该字母后面插入字符串“(max)”
Input
输入数据包括多个测试实例，每个实例由一行长度不超过100的字符串组成，字符串仅由大小写字母构成；第一行表示实例数量
 Output
对于每个测试实例输出一行字符串，输出的结果是插入字符串“(max)”后的结果，如果存在多个最大的字母，就在每一个最大字母后面都插入"(max)"*/
using namespace std;
int main(int argc, char *argv[]) {
    string x;
    int max[100];
    int maxnum;
    while(getline(cin,x)){
        maxnum=0;
        memset(max,0,sizeof(max));
        for(int i=0;i<x.length();i++){
            if(x[i]>x[maxnum]){
                max[maxnum]=0;
                max[i]=1;
                maxnum=i;             
            }else if(x[i]==x[maxnum]){
                max[i]=1;
            }            
        }
        for(int i=0;i<x.length();i++){
            cout<<x[i];
            if(max[i]==1){
                cout<<"(max)";
            }
       } 
    }
}