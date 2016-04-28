#include <iostream>
#include <cstring>
#include <cstdio>
#define N 3
typedef struct Student {
	char name[20];
	char password[10];
	int num;
}student;
using namespace std;
int main(int argc, char *argv[]) {
	student x;
	FILE *fp;
	char c[]="fuck";
	int count,filesize;
	fp=fopen("/Users/dawn/zpy.txt", "rb+");
	fseek(fp,0,SEEK_END);
	filesize=ftell(fp);
	count=filesize/sizeof(student);
	rewind(fp);
	
	for(int i=0;i<count;i++){
		fread(&x,sizeof(student),1,fp);
		filesize=ftell(fp);
		if(x.num==6){
		//	cout<<c<<endl;
			strcpy(x.name,c);
		//	cout<<x.name<<endl;
		//	x.password="cccccc";
			fseek(fp,i*sizeof(student),SEEK_SET);
			errno=0;
			cout<<fwrite(&x, sizeof(student), 1, fp)<<endl;
			perror("haish");
			break;
		}
	}
  //fwrite(x,sizeof(student),N,fp);
  fclose(fp);
	return 0;
}