#include <iostream>
#include <stdio.h>
using namespace std;
#define SEQUEUEFULL 0
#define SEQUEUEEMPLY 0
#define SUCCESS 1
#define MAXSIZE 10
typedef struct{
    int data[MAXSIZE];
    int front,rear;
}c_SeQueue;
void Init_SeQueue(c_SeQueue *q){
    q->front=q->rear=0;
}
int In_SeQueue(c_SeQueue *q,int x){
    if((q->rear+1)%MAXSIZE==q->front){
        return SEQUEUEFULL;
    }else{
        q->rear=(q->rear+1)%MAXSIZE;
        q->data[q->rear]=x;
        return SUCCESS;
    }
}
int Out_SeQueue(c_SeQueue *q,int *x){
    if(q->front==q->rear){
        return SEQUEUEEMPLY;
    }else{
         q->front=(q->front +1)%MAXSIZE;
         *x=q->data[q->front];
        return SUCCESS;
    }
}
int Empty_SeQueue(c_SeQueue *q){
    if(q->rear ==q->front)return 1;
    else return 0;
}
int Full_SeQueue(c_SeQueue *q){
    if((q->rear+1)%MAXSIZE==q->front)return 1;
    else return 0;
}
int main(int argc, char *argv[]) {
    c_SeQueue q,*cq=&q;
    int select,i;
    int y,z;
    Init_SeQueue(cq);
    cout<<"\n(1)Input data"<<endl<<"(2)Output data";
    cout<<"\n(3)Exit"<<endl<<"Please select one=>";
    cin>>select;
    do{
        switch(select){
            case 1:cout<<"\nPlease input the data=>";
            cin>>y;
            In_SeQueue(cq, y);
            cout<<"\nthe elements are:\n";
            for(i=(cq->front+1)%MAXSIZE;i!=(cq->rear+1)%MAXSIZE;i=(i+1)%MAXSIZE){
                cout<<cq->data[i];
            }
            break;
            case 2:Out_SeQueue(cq, &z);
            cout<<"\nthe elements are:\n";
            for(i=(cq->front+1)%MAXSIZE;i!=(cq->rear+1)%MAXSIZE;i=(i+1)%MAXSIZE){
                cout<<cq->data[i];
            }
            break;
                                           
        }
        cout<<"\n(1)Input data"<<endl<<"(2)Output data";
        cout<<"\n(3)Exit"<<endl<<"Please select one=>";
        cin>>select;                        
    }while(select!=3);
    
}