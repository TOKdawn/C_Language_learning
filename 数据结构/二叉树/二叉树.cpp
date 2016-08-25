#include <iostream>
#include <stdlib.h>
int GetValue(int oper,int operl,int oper2);
typedef char TElemType;
typedef struct BTNode{
    TElemType data;
    struct BTNode *lchild,*rchild;
}BTNode;
BTNode *CreateBTree(char *nodelist,int i){
    BTNode *newnode;
    if(nodelist[i]==0||i>7){
        return NULL;
    }else{
        newnode=(BTNode *)malloc(sizeof(BTNode));
        newnode->data=nodelist[i];
        newnode->lchild=CreateBTree(nodelist,2*i);
        newnode->rchild=CreateBTree(nodelist,2*i+1);
        return newnode;
    }
}
//前序递归
void PreTraverse(BTNode *bt){
    if(bt!=NULL){
        cout<<bt->data;
        PreTraverse(bt->lchild);
        PreTraverse(bt->rchild);
    }
    return ;
}
//中序递归
void InTraverse(BTNode *bt){
    if(bt!=NULL){
        InTraverse(bt->lchild);
        cout<<bt->data;
        InTraverse(bt->rchild);
    }
    return ;
}
//后序递归

void PostTraverse(BTNode *bt){
    if(bt!=NULL){
        PostTraverse(bt->lchild);
        PostTraverse(bt->rchild);
        cout<<bt->data;
    }
    return ;
}
int Calculate
using namespace std;
int main(int argc, char *argv[]) {
    
}