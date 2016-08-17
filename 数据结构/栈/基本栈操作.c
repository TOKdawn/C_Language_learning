#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXSIZE 10
#define SEQSTACKFULL 1
#define SEQSTACKEMPTY 1
#define TURE 1
#define FOUR 0
#define SUCESS 0
/*栈顶指针在第一个数据上一位*/
typedef struct{
      int data[MAXSIZE];
      int top;
}SeqStack;
void Init_SeqStack(SeqStack *s){
      s->top=0;
}
int Empty_SeqStack(SeqStack *s){
      if(s->top==0)return TURE;
      else return FOUR;
}
int Push_SeqStack(SeqStack *s,int x){
      if(s->top==MAXSIZE){
            return SEQSTACKFULL;
      }
      s->data[s->top]=x;
      s->top++;
      return SUCESS;
      
}
int Pop_Seqstack(SeqStack *s,int *x){
      if(s->top==0){
            return SEQSTACKEMPTY;
      }
      s->top--;
      *x=s->data[s->top];
      return SUCESS;
}
int Top_Seqstack(SeqStack *s,int *x){
      if(s->top==0){
            return SEQSTACKEMPTY;
      }
      *x=s->data[s->top-1];
      return SUCESS;
}
int main(int argc, char *argv[]) {
      SeqStack ss;
      int select,i,flag;
      int y,z;
      Init_SeqStack(&ss);
      cout<<"\n(1)Input a stack data."<<endl<<"(2)Output a stack data";
      cout<<"\n(3)Exit"<<endl<<"Please select one=>";
      cin>>select;
      do{
            switch(select){
                  case 1:cout<<"\nPlease input the data=>";
                         cin>>y;
                         flag=Push_SeqStack(&ss, y);
                         if(flag==0){
                              cout<<"\nthe element are:"<<endl;
                              for(i=0;i<ss.top;i++){
                                    cout<<ss.data[i];
                              }
                         }else{
                                    cout<<"Stack is full"<<endl;
                              }
                              break;
                   case 2:flag=Pop_Seqstack(&ss, &z);
                          if(flag==0){
                              cout<<"\nthe element are:"<<endl;
                              for(i=0;i<ss.top;i++){
                                    cout<<ss.data[i];
                              }
                          }else{
                                    cout<<"Stack is empty"<<endl;
                              }
                          break;                                 
            }
            cout<<"\n(1)Input a stack data."<<endl<<"(2)Output a stack data";
            cout<<"\n(3)Exit"<<endl<<"Please select one=>";
            cin>>select;
            cout<<endl;
      }while(select!=3);
      return SUCESS;     
}