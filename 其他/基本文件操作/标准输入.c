#include <iostream>
#include <string.h>
#include <stdio.h>
#define N 3
typedef struct Student {
	char name[20];
	char password[10];
	int num;	
}student;
using namespace std;
int main(int argc, char *argv[]) {
	FILE *fp;
	student x[N];
	for(int i=0;i<N;i++){
		printf("请输入第%d个学生的姓名数据\n",i+1);
		scanf("%s",x[i].name);
		scanf("%s",x[i].password);
		scanf("%d",&x[i].num);
	}
	fp = fopen("/zpy.txt","wb");
	if(fp==NULL){
    printf("文件打开错误");
    return 0;
  }
  fwrite(x,sizeof(student),N,fp);
  fclose(fp);
	return 0;
}