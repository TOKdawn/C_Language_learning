#include <iostream>
#include <stdio.h>
//"/Users/dawn/zpy/studentinformation.txt"
#define FILRADRESS "/Users/dawn/zpy/userinformation.txt"//文件路径
#define USERNAMELONGER 20//用户名最大长度
#define PASSWORDLONGER 16//密码最大长度
typedef struct _Admin{//登录用户
    char userName[USERNAMELONGER];//用户名
    char passWord[PASSWORDLONGER];//密码
    int ad_type;//用户类型标识
    
}Admin;
using namespace std;
void show(FILE *fp){
    Admin x;
    int count,filesize;
   
    fseek(fp, 0, SEEK_END);
    filesize = ftell(fp);
    count=filesize/sizeof(Admin);
    cout<<"结构体数量"<<count<<"文件大小"<<filesize<<endl;
    rewind(fp);
    for(int i=0;i<count;i++){
        fread(&x, sizeof(Admin), 1, fp);
        cout<<x.userName<<endl;
        cout<<x.passWord<<endl;
        cout<<x.ad_type<<endl<<endl;
    }
    fclose(fp);
}
void Input(){
    Admin x;
    int count;
    FILE *fp;
    cout<<"请输入用户名"<<endl;
    cin>>x.userName;
    cout<<"请输入密码"<<endl;
    cin>>x.passWord;
    cout<<"请输入用户类型(1.老师 2.学生)"<<endl;
    cin>>x.ad_type;
    fp = fopen(FILRADRESS, "ab");  
    if (fp == NULL) {
        printf("文件打开错误");
        return ;
    }
    fseek(fp, 0, SEEK_END);  
    fwrite(&x, sizeof(Admin), 1, fp);
    fclose(fp);
}
int main(int argc, char *argv[]) {
    Admin x;
    FILE *fp;
    int count,filesize,flag;
    fp=fopen(FILRADRESS,"rb");
    if(fp==NULL){
        cout<<"文件打开失败"<<endl;
    }
    cout<<"1.输入"<<endl<<"2.显示"<<endl<<"3.结束"<<endl;
    while(cin>>flag){
        cout<<"1.输入"<<endl<<"2.显示"<<endl<<"3.结束"<<endl;
        if(flag==3){
            return 0;
        }
        if(flag==2){
            show(fp);
        }
        if(flag==1){
            Input();
        }
        
    }
}