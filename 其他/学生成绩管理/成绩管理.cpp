#include <iostream>
#include <stdlib.h>
#include <string.h>
//#include <Windows.h>
#define MAXNUM 10         //成绩个数
#define USERNAMELONGER 20 //用户名最大长度
#define PASSWORDLONGER 16 //密码最大长度
#define ENGLISH 0         //英语在成绩数组里的下表
#define MATH 1            //同理数学
#define CHINESE 2         //语文
#define TEACHER 1         //老师标识符
#define STUDENT 2         //学生标识符
#define ADMINERROR -1     //身份验证错误
#define FILRADRESS "/Users/dawn/zpy/userinformation.txt" //文件路径
#define STUDENTADRESS "/Users/dawn/zpy/studentinformation.txt"
using namespace std;
/*****结构体*****/
typedef struct _Student { //学生数据
  string Student_num;        //学号
  string Student_name;      //姓名
  double score[MAXNUM];   //成绩
  char Class[10];
  struct _Student *next;
} Student;
typedef struct _Admin {          //登录用户
  char userName[USERNAMELONGER]; //用户名
  char passWord[PASSWORDLONGER]; //密码
  int ad_type;                   //用户类型标识
  
} Admin;
/**********函数声明*************/
void Menushow(int TYPE);
int admincheak(char *Name, char *Password);
void ScoreManage(Student *p);
void ScoreSearch(Student *p);
Student *LondData(void);                           //读取文件
int InitList(Student **list, int count, FILE *fp); //创建链表
void Input(void);

int main(int argc, char *argv[]) {
  Admin visitor;
  int TYPE = -1, i;
  cout << "***************************************" << endl;
  cout << "**************学生成绩查询***************" << endl;
  cout << "***************************************" << endl;
  for (i = 0; i < 3; i++) {
    cout << "**************请输入用户名***************" << endl;
    cin >> visitor.userName;
    //    system("cls");
    cout << "***************请输入密码****************" << endl;
    cin >> visitor.passWord;
    TYPE = admincheak(visitor.userName, visitor.passWord);
    if (TYPE != ADMINERROR)
      break;
    printf("用户名或密码错误，请重新输入（还有%d次机会）\n", 2 - i);
  }
  if (TYPE == ADMINERROR) {
    cout << "系统结束" << endl;
    //          Sleep(2000);
    return 0;
  } else
    Menushow(TYPE);
  system("pause");
  return 0;
}
int admincheak(char *Name, char *Password) {
  FILE *fp;
  int filesize, count, i, type = -1;
  Admin tempUser;
  if ((fp = fopen(FILRADRESS, "rb")) == NULL) {
    cout << "文件打开失败" << endl;
    return -1;
  }
  fseek(fp, 0, SEEK_END);           //文件指针置到文件尾
  filesize = ftell(fp);             //计算文件大小
  count = filesize / sizeof(Admin); //文件中含结构体的数目
  rewind(fp);
  for (i = 0; i < count; i++) {
    fread(&tempUser, sizeof(Admin), 1, fp); //取一个结构体
    if (strcmp(tempUser.userName, Name) == 0 &&
        strcmp(tempUser.passWord, Password) == 0) {
      type = tempUser.ad_type;
      system("cls");
    }
  }
  fclose(fp);
  return type;
}
void Menushow(int TYPE) {
  int x;
  Student *p = NULL;   //链表指针;
  p = LondData();      //从文件中读取学生成绩并存为链表;
  int _user, _teacher; //用户对各个系统的使用权限;
  _user = _teacher = 0;
  switch (TYPE) { //读取用户表示并且分配权限
    case TEACHER:
      _user = 1;
      _teacher = 1;
      break;
    case STUDENT:
      _user = 1;
      _teacher = 0;
  }
  cout << "***************************************" << endl;
  cout << "***************1.成绩管理***************" << endl;
  cout << "***************2.成绩查询***************" << endl;
  cout << "***************3.退出系统***************" << endl;
  cout << "***************************************" << endl;
  while (cin >> x) {
    if (x == 3)
      break;
    switch (x) {
      case 1:
        if (!_teacher)
          cout << "权限不足" << endl;
        else
          ScoreManage(p);
        break;
      case 2:
        ScoreSearch(p);
        break;
    }
    cout << "*************请输入下一个命令**************" << endl;
  }
}
int InitList(Student **_list,int count,FILE *fp) {
  Student *Nextlist;
  Student *Thislist;
  *_list = (Student *)malloc(sizeof(Student));
  if (*_list == NULL) {
    return 1;
  }
  fread(*_list, sizeof(Student), 1, fp);
  Thislist = *_list;
  for (int i = 1; i < count; i++) {
    Nextlist = (Student *)malloc(sizeof(Student));
    if (Nextlist == NULL) {
      return 1;
    }
    fread(Nextlist, sizeof(Student), 1, fp);
    Thislist->next = Nextlist;
    Thislist = Nextlist;
  }
  Thislist->next=NULL;
  return 0;
}
Student *LondData() {
  Student *list;
  Student **_list;
  _list = &list; //指针传递变量,主函数分配内存空间,子函数使用.
  
  FILE *fp;
  Student x;
  int count, filesize;
  fp = fopen(STUDENTADRESS, "rb");
  if (fp == NULL) {
    cout << "文件打开失败111" << endl;
    return NULL;
  }
  fseek(fp, 0, SEEK_END);
  filesize = ftell(fp);
  count = filesize / sizeof(Student);
  rewind(fp);
  switch (InitList(_list, count,fp)) { //多可能性函数调用,可以根据返回值具体显示错误原因
    case 1:
      cout << "申请内存空间失败,请退出" << endl;
      break;
    case 0:
      cout << "系统加载成功" << endl;
      break;
    default:
      cout << "未知错误,请退出" << endl;
  }
  fclose(fp);
  return list;
}
void Input() {
  Student x;
  FILE *fp;
  if ((fp = fopen(STUDENTADRESS, "ab")) == NULL) {
    cout << "文件打开失败" << endl;
    return;
  }
     // fp = fopen(STUDENTADRESS, "ab");
  cout << "请输入学生姓名:" << endl;
  cin >> x.Student_name;
  cout << "请输入学生学号:" << endl;
  cin >> x.Student_num;
  cout << "语文成绩:" << endl;
  cin >> x.score[0];
  cout << "数学成绩:" << endl;
  cin >> x.score[1];
  cout << "英语成绩:" << endl;
  cin >> x.score[2];
  fseek(fp, 0, SEEK_END);
  fwrite(&x, sizeof(Student), 1, fp);
  fclose(fp);
}
void Show() {
  Student x;
  FILE *fp;
  int filesize,count;
  if ((fp = fopen(STUDENTADRESS, "rb")) == NULL) {
    cout << "文件打开失败" << endl;
    return;
  }
  fseek(fp, 0, SEEK_END);
  filesize = ftell(fp);
  count = filesize / sizeof(Student);
  cout << "结构体数量" <<count << "文件大小" << filesize << endl;
  rewind(fp);
  for (int i = 0; i < count; i++) {
    fread(&x, sizeof(Student), 1, fp);
    cout << x.Student_name << endl;
    cout << x.Student_num << endl;
    cout << "语文:" << x.score[0] << endl;
    cout << "数学:" << x.score[1] << endl;
    cout << "英语:" << x.score[2] << endl;
  }
  fclose(fp);
}
void ScoreManage(Student *p) {
  int x = 1;
  cout << "1.开始输入";
  while (cin >> x) {
    cout << "1.继续,2.显示" << endl;
    if (x == 1) {
      Input();
    } else if (x == 2) {
      Show();
    }
  }
  return;
}
void ScoreSearch(Student *p) { cout << "成绩查询"; }

//
