char *p[3]={"zpy","cxh","sry"};

char p[3][4]={"zpy","cxh","sry"};

char **P=(char **)malloc(sizeof(char *)*3);
for(int i=0;i<3;i++){
      p[i]=(char *)malloc(sizeof(char)*4);
      strcpy(p[i],"zpy");
}
中的zpy分别存在哪部分内存中（）
A.常量，堆，栈          B.栈，堆，栈
C.常量，堆，堆          D.栈，堆，堆
E.常量，栈，堆          F.栈，栈，堆
//E
