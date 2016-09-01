#include <stdio.h>
void main()
{
      char str[100]
      char subStr[10]
      int num,i;
      do{
		gets(str);	
	if(str!="0"){
		gets(subStr);
	
   	 num = count(str, subStr);
      printf("%d",num);
}
   }while(str=="0");
}
int count(char* str, char* subStr)
{
      int i, j, k, num = 0;
      for(i=0; str[i]!='\0'; i++)
{
            for (j=i, k = 0; str[j] == subStr[k] && str[j]!='\0'; k++,j++);
            if (subStr[k]=='\0')
                  num++;
}
      return num;
}