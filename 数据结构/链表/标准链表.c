#include <stdio.h>
#include <stdlib.h>
#define NOT_FIND 4
#define NUM_ERROR 3
#define LIST_EMPTY 2
#define MALLOC_ERR 1
#define FUNC_EXIT_SUCESS 0
typedef int ElemType; //设定链表所储存的数据类型
typedef struct TheList {
  ElemType data;
  struct TheList *next;
} str_List; //链表结构重命名为str_List
/**********函数声明*******/
int InitList(
    str_List **list,
    int sum /*  ElemType *input 输入获取途径,本程序为在函数里获取键盘输入,可扩展其他方式*/); //创建链表,长度为sum
int ClearList(str_List *list); //清空链表
int ShowList(str_List *list);  //打印链表
int GetElem(int num, ElemType *elem,
            str_List *list); //查找链表第num个元素,值给elem
int LocateElem(int num, str_List *list,
               int *result); //在链表中查询数据,result返回数据所在位置,
int ListInsert(int num, ElemType elem,
               str_List *liet); //在链表的num位置插入数据elem
int ListDelete(int num, ElemType *elem,
               str_List *list); //在链表中删除第num元素,并且返回所删除的值
int ListLength(str_List *list, int *sum); //返回链表元素个数
/**********声明结束*******/
int main(int argc, char const *argv[]) {
  str_List *list;
  int *e;
  int d =
      10; //用指针传递参数前务必记得为先声明变量并且赋值,否则直接声明的指针指向NULL会出BUG
  e = &d;
  str_List **delivery;
  delivery = &list;
  // InitList(delivery, 4);
  // ListLength(list, e);
  // ListDelete(3, e, list);
  // ShowList(list);
  // LocateElem(20, list, e);
  // GetElem(2, e, list);
  // printf("%d", *e);
  // printf("\n");
  // ListInsert(2, 100, list);
  // GetElem(3, e, list);
  // printf("%d查找\n", *e);
  // ShowList(list);
  return 0;
}
int ShowList(str_List *head) {
  str_List *p;
  p = head;
  if (head == NULL)
    return LIST_EMPTY;
  do {
    printf("%d\n", p->data);

  } while ((p->next) != NULL && (p = p->next)); //先判断后移动链表....
  return FUNC_EXIT_SUCESS;
}
int InitList(str_List **head, int sum) {
  str_List *p;
  str_List *r;
  int i;
  *head = (str_List *)malloc(sizeof(str_List));
  if (*head == NULL)
    return MALLOC_ERR;
  // /*此种读取需要,跟换读取方式请删除注释
  printf("请输入链表第一个储存数据");
  scanf("%d", &((*head)->data));
  system("cls");
  // */此种读取需要,跟换读取方式请删除注释
  r = *head;
  for (i = 1; i < sum; i++) {
    p = (str_List *)malloc(sizeof(str_List));
    if (p == NULL)
      return MALLOC_ERR;
    // /*此种读取需要,跟换读取方式请删除注释
    printf("请输入链表第%d个储存数据", i + 1);
    scanf("%d", &(p->data));
    system("cls");
    // */此种读取需要,跟换读取方式请删除注释
    r->next = p;
    r = p;
  }
  r->next = NULL;
  return FUNC_EXIT_SUCESS;
}
int GetElem(int num, ElemType *elem, str_List *list) {
  str_List *p = list;
  if (p == NULL) {
    return LIST_EMPTY;
  }
  int i = 1;
  while (p && i < num) {
    p = p->next;
    i++;
  }
  if (!p || i > num) //判断第num个元素是否存在
    return NUM_ERROR;
  *elem = p->data;
  return FUNC_EXIT_SUCESS;
}
int ListInsert(int num, ElemType elem, str_List *list) {
  if (list == NULL) {
    return LIST_EMPTY;
  }
  str_List *p;
  str_List *s;
  int j = 1;
  p = list;
  while (p && j < num) {
    p = p->next;
    j++;
  }
  if (!p || j > num)
    return NUM_ERROR;
  s = (str_List *)malloc(sizeof(str_List));
  if (s == NULL) {
    return MALLOC_ERR;
  }
  s->data = elem;
  s->next = p->next;
  p->next = s;
  return FUNC_EXIT_SUCESS;
}
int ClearList(str_List *list) {
  str_List *p, *q;
  p = list->next;
  free(list);
  while (p) {
    q = p->next;
    free(p);
    p = q;
  }
  list->next = NULL;
  return FUNC_EXIT_SUCESS;
}
int LocateElem(int num, str_List *list, int *result) {
  str_List *p;
  p = list;
  while (p == NULL) {
    return LIST_EMPTY;
  }
  int i = 1;
  while (p->data != num && p->next != NULL) {
    i++;
    p = p->next;
  }
  if (p->next == NULL) {
    return NOT_FIND;
  }
  *result = i;
  return FUNC_EXIT_SUCESS;
}
int ListDelete(int num, ElemType *elem, str_List *list) {
  str_List *p, *q, *t;
  int i;
  p = list;
  if (p == NULL) {
    return LIST_EMPTY;
  }
  for (i = 1; i < num - 1; i++) {
    p = p->next;
  }
  t = p->next;
  q = t->next;
  *elem = t->data;
  free(t);
  p->next = q;
  return FUNC_EXIT_SUCESS;
}
int ListLength(str_List *list, int *num) {
  str_List *p;
  p = list;
  if (p == NULL) {
    return LIST_EMPTY;
  }
  if (p->next == NULL) {
    *num = 1;
    return FUNC_EXIT_SUCESS;
  }
  int i = 1;
  do {
    p = p->next;
    i++;
  } while (p->next != NULL);
  *num = i;
  return FUNC_EXIT_SUCESS;
}
