/***代码填空***/
/*问号处添加代码*/
/*加油*//*>_<*/
/*From Dawn*/
#include <stdio.h>
#include <stdlib.h>
#define MALLOC_ERR 1
#define Array_num 8
#define FUNC_EXIT_SUCESS 0
typedef int ElemType;
typedef ElemType (*Array) [Array_num];
int func3(int *a) {
	int i, j, temp;
	for (j = 0; j < Array_num - 1; j++)
		for (i = 0; i < Array_num - 1 - j; i++)
		{
			if (a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	return FUNC_EXIT_SUCESS;
}
int func2(??)//Array LZW
{
	func3(*LZW);
	return FUNC_EXIT_SUCESS;
}
int func1(??)//Array *YY
{
	func2(*YY);
	return FUNC_EXIT_SUCESS;
}

int main() {
	int ZPY[Array_num] = { 1,9,9,6,0,4,0,4 };
	Array *SRY;
	Array CXH;
	? ? = ? ? ;				//	SRY = &CXH;
	? ? = ? ? ;				//	CXH = &ZPY;
	func1(SRY);
	for (int i = 0;i < 8;i++) {
		printf("%d ", ZPY[i]);
	}
	system("pause");
	return FUNC_EXIT_SUCESS;

}
