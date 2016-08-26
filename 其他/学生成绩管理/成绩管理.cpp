#include <iostream>
#include <stdlib.h>
#include <string.h>
//#include <Windows.h>
#define MAXNUM 10//成绩个数
#define USERNAMELONGER 20//用户名最大长度
#define PASSWORDLONGER 16//密码最大长度
#define ENGLISH 0//英语在成绩数组里的下表
#define MATH 1//同理数学
#define CHINESE 2//语文
#define TEACHER 1//老师标识符
#define STUDENT 2//学生标识符
#define ADMINERROR -1//身份验证错误
#define FILRADRESS "/Users/dawn/zpy/userinformation.txt"//文件路径

/*****结构体*****/
typedef struct _Student{//学生数据
    int Student_num;//学号
    char Student_name;//姓名
    double score[MAXNUM];//成绩
    char Class[10];
}Student;
typedef struct _Admin{//登录用户
    char userName[USERNAMELONGER];//用户名
    char passWord[PASSWORDLONGER];//密码
    int ad_type;//用户类型标识
    
}Admin;
/**********函数声明*************/
void Menushow(int TYPE);
int admincheak(char *Name, char *Password);
using namespace std;
int main(int argc, char *argv[]) {
    Admin visitor;
    int TYPE=-1 ,i;
    cout<<"***************************************"<<endl;
    cout<<"**************学生成绩查询***************"<<endl;
    cout<<"***************************************"<<endl;
    for (i = 0; i < 3; i++) {
        cout<<"**************请输入用户名***************"<<endl;
        cin>>visitor.userName;
        //    system("cls");
        cout<<"***************请输入密码****************"<<endl;
        cin>>visitor.passWord;
        TYPE = admincheak(visitor.userName, visitor.passWord);
        if (TYPE != ADMINERROR)
            break;
        printf("用户名或密码错误，请重新输入（还有%d次机会）\n", 2 - i);
    }
    if (TYPE == ADMINERROR) {
        cout<<"系统结束"<<endl;
        //          Sleep(2000);
        return 0;
    }
    else
        Menushow(TYPE);
    system("pause");
    return 0;
}
int admincheak(char *Name, char *Password){
    FILE *fp;
    int filesize, count,i,type = -1;
    Admin tempUser;
    if((fp = fopen("FILRADRESS", "rb"))==NULL){
        cout<<"文件打开失败"<<endl;
        return -1;
    }
    fseek(fp, 0, SEEK_END);//文件指针置到文件尾
    filesize = ftell(fp);//计算文件大小
    count = filesize /sizeof(Admin);//文件中含结构体的数目
    for(i=0;i<count;i++){
        fread(&tempUser,sizeof(Admin),1,fp);//取一个结构体
        if (strcmp(tempUser.userName, Name) == 0 && strcmp(tempUser.passWord, Password) == 0) {
            type = tempUser.ad_type;
            system("cls");
        }
    }
    fclose(fp);
    return type;
}
void Menushow(int TYPE){
    cout<<"shpw";
}








