#include <stdio.h>
//#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#define ADMINERROR 0
#define READER 1
#define LIBRARIANS 2
#define SYSTEM_ADMINISTRATOR 3
int TYPE;
int ADMIN_NUM;
typedef struct Admin_type {
	int ad_type;
	char userName[10];
	char passWord[10];
	int broowbook;
	int bookMax;
	int booknum;
	int admin_num;
}admin_type;

admin_type* londdata();
void Menushow();
void user();
void reader();
void book();
void Book();
void user_input();
void user_change();
void changename();
void changepassword();
void changetype();
void changebookmax();
void user_del();
void user_show();
void user_passworld();
void reader_input();
void reader_change();
void reader_del();
void reader_show();
void reader_find();
	void broowBook();
void returnBook();
void book_input();
void book_change();
void book_find();
void book_total();
void findname();
void findnum();
void findwriter();
void findpress();
int admincheak(char *Name, char *Password);

int main() {
	admin_type visitor;
	int type, i;
	printf("***************************************\n");
	printf("*************图书管理系统**************\n");
	printf("***************************************\n");
	printf("*************请输入用户名**************\n");
	gets(visitor.userName);
	printf("**************请输入密码***************\n");
	gets(visitor.passWord);
	system("cls");
	for (i = 0; i < 3; i++) {
		TYPE = admincheak(visitor.userName, visitor.passWord);
		if (TYPE != ADMINERROR)
			break;
		printf("用户名或密码错误，请重新输入（还有%d次机会）", 2 - i);
	}

	if (TYPE == ADMINERROR) {
		printf("系统结束");
     //       Sleep(2000);
		return 0;
	}
	else
		Menushow();


	system("pause");

}
int admincheak(char *Name, char *Password) {
	FILE *fp;
	int filesize, count, i, type = -1;
	admin_type tempUser;
	if ((fp = fopen("userinformation.txt", "rb")) == NULL) {
		printf("打开文件失败\n");
		return 0;
	}
	fseek(fp, 0, 2);
	filesize = ftell(fp);
	rewind(fp);
	count = filesize / sizeof(admin_type);
	for (i = 0;i < count;i++) {
		fread(&tempUser, sizeof(admin_type), 1, fp);
		if (strcmp(tempUser.userName, Name) == 0 && strcmp(tempUser.passWord, Password) == 0) {
			type = tempUser.ad_type;
			ADMIN_NUM=tempUser.admin_num;
			system("cls");
		}
	}
	fclose(fp);
	return type;
}
void Menushow() {
	void *p;
	p=londdata();
	int x;
	int _user, _reader, _book, _Book, _exit;
	_user = _reader = _book = _Book = _exit = 0;
	switch (TYPE) {
	case READER:
		_user = 1;
		_book = 1;
		_exit = 1;
		break;
	case LIBRARIANS:
		_book = 1;
		_Book = 1;
		_exit = 1;
		break;
	case SYSTEM_ADMINISTRATOR:
		_reader = 1;
		_user = 1;
		_exit = 1;
		break;
	}
	printf("***************************************\n");
	//		if (_user)
	printf("               1.用户管理              \n");
	//		if (_reader)
	printf("               2.读者管理              \n");
	//		if (_book)
	printf("               3.读书管理              \n");
	//		if (_Book)
	printf("               4.读书流管理            \n");
	//		if (_exit)
	printf("               5.退出系统              \n");
	printf("***************************************\n");
	while (~scanf("%d", &x)) {
		if (x == 5)
			break;
		switch (x) {
		case 1:
			if (!_user)
				printf("权限不足");
			else
				user();
			break;
		case 2:
			if (!_reader)
				printf("权限不足");
			else
				reader();
			break;
		case 3:
			if (!_book)
				printf("权限不足");
			else
				book();
			break;
		case 4:
			if (!_Book)
				printf("权限不足");
			else
				Book();
			break;
		}
		printf("*************请输入下个指令************\n");
	}

}



//用户信息处理模块
void user() {
	int x;
	printf("***************************************\n");
	//	if (_user)
	printf("            1.用户信息输入              \n");
	//	if (_reader)
	printf("            2.用户信息修改              \n");
	//	if (_book)
	printf("            3.用户信息删除              \n");
	//	if (_Book)
	printf("            4.用户信息显示              \n");
	//	if (_exit)
	printf("            5.用户密码修改              \n");
	printf("            6.返回主菜单                \n");
	printf("***************************************\n");
	while (~scanf("%d", &x)) {
		if (x == 6)
			break;
		switch (x) {
		case 1:
			if (TYPE != SYSTEM_ADMINISTRATOR)
				printf("权限不足");
			else
				user_input();
			break;
		case 2:
			user_change();
			break;
		case 3:
			if (TYPE != SYSTEM_ADMINISTRATOR)
				printf("权限不足");
			else
				user_del();
			break;
		case 4:
			if (TYPE != SYSTEM_ADMINISTRATOR)
				printf("权限不足");
			else
				user_show();
			break;
		case 5:
			user_passworld();
		}

	}
	return;

}
void user_input(){//用户信息储存在根下,userinformation
	admin_type newadmin;
	int num;
	char password1[10],password2[10];
	FILE *fp;
	if((fp=fopen("userinformation.txt","ab"))==NULL){
		printf("文件打开失败\n");
		return ;
	}
		fseek(fp,-sizeof(admin_type),SEEK_END);//读取当前文件里最后一个结构体地址首
		fread(&newadmin,sizeof(newadmin),1,fp);//读取当前文件最后一个学生数据编号
		rewind(fp);//还原指针位置
		printf("***************************************\n");
		printf("              新用户信息输入             \n");
		printf("***************************************\n");
		printf("请输入用户名\n");
		scanf("%s",newadmin.userName);
		printf("请输入密码\n");
		scanf("%s",password1);
		printf("请再次输入密码\n");
		scanf("%s",password2);
		if((strcmp(password1,password2)!=0)){
			printf("两次输入不同.\n");
			fclose(fp);
			return;
		}
		strcpy(newadmin.passWord,password1);
		newadmin.admin_num++;
		printf("请输入用户类型\n");
		printf("1.普通读者\n");
		printf("2.图书管理员\n");
		printf("3.系统管理员\n");
		scanf("%d",&newadmin.ad_type);
		fseek(fp,0,SEEK_END);
		if(fwrite(&newadmin,sizeof(admin_type),1,fp)!=1){
			printf("文件写入失败\n");
			fclose(fp);
			return ;
		}
		fclose(fp);
}
void user_change(){
	admin_type newadmin;
	int filesize,count,i,j,number,flag=0,x;
	FILE *fp;
	fp=fopen("userinformation","rb");
	if(fp==NULL){
		printf("文件打开失败/n");
		return ;
	}
	fseek(fp,0,SEEK_END);
	filesize =ftell(fp);
	rewind(fp);
	count = filesize/sizeof(admin_type);
	printf("请输入要更改的用户编号:\n");
	scanf("%d",&number);
	for(i=0;i<count;i++){
		fread(&newadmin,sizeof(admin_type),1,fp);
		if(newadmin.admin_num==number){
			filesize=ftell(fp);//并不知道这里是否就是文件的当前位置指针
			flag=1;
			printf("用户名:%s\n密码:%s\n编号%d\n",newadmin.userName,newadmin.passWord,newadmin.admin_num);
			switch (newadmin.ad_type) {
				case 1:
				printf("普通用户\n");
				break;
				case 2:
				printf("图书管理员\n");
				break;
				case 3:
				printf("系统管理员\n");
			}
			printf("可借书数目:%d\n",newadmin.bookMax);
			printf("已借书数目:%d\n",newadmin.booknum);
			if(newadmin.booknum!=0){
				for(j=0;j<newadmin.booknum;j++)
				printf("已借书编号:%d\n",newadmin.booknum);
			}
			printf("\n\n");
			printf("请输入要修改的项目.\n");
			printf("***************************************\n");
			printf("                 1.用户名               \n");
			printf("                 2.密码                 \n");
			printf("                 3.用户类型              \n");
			printf("                 4.可借书数              \n");
			printf("                 5.修改结束              \n");
			printf("***************************************\n");
			while(~scanf("%d",&x)){
				if(x==6)
					break;
					switch (x) {
						case 1:
						changename();
						break;
						case 2:
						changepassword();
						break;
						case 3:
						changetype();
						break;
						case 4:
						changebookmax();
						break;
					}
			}





		}
	}
	if(flag==0){
		printf("编号错误\n");
		//break;
	}
	fclose(fp);
	return ;
}

void user_del();
void user_show(){
	admin_type newadmin;
	int filesize,count,i,j;
	FILE *fp;
	fp=fopen("userinformation","rb");
	if(fp==NULL){
		printf("文件打开失败/n");
		return ;
	}
	fseek(fp,0,SEEK_END);
	filesize =ftell(fp);
	rewind(fp);
	count = filesize/sizeof(admin_type);
	for(i=0;i<count;i++){
		fread(&newadmin,sizeof(admin_type),1,fp);
		printf("用户名:%s\n密码:%s\n编号%d\n",newadmin.userName,newadmin.passWord,newadmin.admin_num);
		switch (newadmin.ad_type) {
			case 1:
			printf("普通用户\n");
			break;
			case 2:
			printf("图书管理员\n");
			break;
			case 3:
			printf("系统管理员\n");
		}
		printf("可借书数目:%d\n",newadmin.bookMax);
		printf("已借书数目:%d\n",newadmin.booknum);
		if(newadmin.booknum!=0){
			for(j=0;j<newadmin.booknum;j++)
			printf("已借书编号:%d\n",newadmin.booknum);
		}
		printf("\n\n");
	}
	fclose(fp);
	return ;
}
void user_passworld();


//用户信息处理模块结束

void reader() {
	int x;
	printf("***************************************\n");
	//	if (_user)
	printf("            1.读者信息输入              \n");
	//	if (_reader)
	printf("            2.读者信息修改              \n");
	//	if (_book)
	printf("            3.读者信息删除              \n");
	//	if (_Book)
	printf("            4.读者信息查询              \n");
	//	if (_exit)
	printf("            5.读者信息显示              \n");
	printf("            6.返回主菜单                \n");
	printf("***************************************\n");
	while (~scanf("%d", &x)) {
		if (x == 6)
			break;
		switch (x) {
		case 1:
			reader_input();
			break;
		case 2:
			reader_change();
			break;
		case 3:
			reader_del();
			break;
		case 4:
			reader_show();
			break;
		case 5:
			reader_find();
		}
	}
	return;
}
void book() {
	int x;
	printf("***************************************\n");
	//	if (_user)
	printf("            1.图书信息输入              \n");
	//	if (_reader)
	printf("            2.图书信息修改              \n");
	//	if (_book)
	printf("            3.图书信息查询              \n");
	//	if (_Book)
	printf("            4.汇总统计                  \n");
	//	if (_exit)
	printf("            6.返回主菜单                \n");
	printf("***************************************\n");
	while (~scanf("%d", &x)) {
		if (x == 6)
			break;
		switch (x) {
		case 1:
			if (TYPE != LIBRARIANS)
				printf("权限不足");
			else
				book_input();
			break;
		case 2:
			if (TYPE != LIBRARIANS)
				printf("权限不足");
			else
				book_change();
			break;
		case 3:
			book_find();
			break;
		case 4:
			book_total();
			break;

		}

	}
	return;
}
void Book() {
	int x;
	printf("***************************************\n");
	printf("              1.借书处理               \n");
	printf("              2.还书处理               \n");
	printf("              3.返回主菜单             \n");
	printf("***************************************\n");
	while (~scanf("%d", &x)) {
		if (x == 3)
			break;
		switch (x) {
		case 1:
			broowBook();
			break;
		case 2:
			returnBook();
			break;
		}
	}
	return;

}
void book_find() {
	int x;
	printf("***************************************\n");
	//	if (_user)
	printf("            1.按书号查询               \n");
	//	if (_reader)
	printf("            2.按书名查询               \n");
	//	if (_book)
	printf("            3.按作者查询              \n");
	//	if (_Book)
	printf("            4.按出版社查询              \n");
	//	if (_exit)
	printf("            5.返回上一层                \n");
	printf("***************************************\n");
	while (~scanf("%d", &x)) {
		if (x == 5)
			break;
		switch (x) {
		case 1:
			findnum();
			break;
		case 2:
			findname();
			break;
		case 3:
			findwriter();
			break;
		case 4:
			findpress();
			break;
		}
	}
	return;
}