#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct LNode{
   int front,rear;
   int data[1000];
}LNode,*List;
void DeList(List l,int &e);
void EnList(List l,int e);
int EmptyList(List l);
int main(){
	List L1,L2;
	int n,k,e,j=0,i;
	L1=(List)malloc(sizeof(LNode));
	L2=(List)malloc(sizeof(LNode));
	L1->front=L1->rear=0;
	L2->front=L2->rear=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>k;
		if(k%2!=0) EnList(L1,k);//��������A���ڰ��� 
		if(k%2==0) EnList(L2,k);//ż������B���ڰ��� 
	}
	while((!EmptyList(L1))||(!EmptyList(L2)))
	{
		if(!EmptyList(L1)){
			for(i=0;i<2;i++){
				DeList(L1,e);
				if(j!=0) cout<<" ";
				cout<<e;
				j++;
			}
		}
		if(!EmptyList(L2)){
			DeList(L2,e);
				if(j!=0) cout<<" ";
				cout<<e;
				j++;
		}
	}
}

void DeList(List l,int &e){//������ 
	e=l->data[l->front];
	l->front++;
}

void EnList(List l,int e){//������ 
	l->data[l->rear]=e;
	l->rear++;
}

int EmptyList(List l){//�ж϶����Ƿ�Ϊ�� 
	return l->front==l->rear;
}

