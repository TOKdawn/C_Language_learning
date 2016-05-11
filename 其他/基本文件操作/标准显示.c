#include <iostream>
#include <stdio.h>
using namespace std;
typedef struct Student {
	char name[20];
	char password[10];
	int num;	
}student;
int main(int argc, char *argv[]) {
	student x;
	FILE *fp;
	int count,filesize;
	fp=fopen("/Users/dawn/zpy.txt", "rb");
	if (fp==NULL){
		printf("文件打开错误");
	}
	fseek(fp,0,SEEK_END);
	filesize=ftell(fp);
	count=filesize/sizeof(student);
	printf("count=%d, filesize=%d\n", count, filesize);
	rewind(fp);
	for(int i=0;i<count;i++){
		fread(&x,sizeof(student),1,fp);
		//scanf("%s",x.name);
		puts(x.name);
		puts(x.password);
		printf("%d",x.num);
		printf("\n");
		printf("\n");
	}
	fclose(fp);
	return 0;
}
