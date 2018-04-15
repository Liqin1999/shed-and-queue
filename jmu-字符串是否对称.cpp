#include<iostream>
#include<stdlib.h>
using namespace std;
typedef char Pos;
typedef int Elemtype;
typedef struct LNode{
	Pos *Data;
	Elemtype Top;
}LNode,*Strack;
void  Push(Strack s,char t);
void  Pop(Strack s,char &e);
int main(){
    Strack L;
    Elemtype i,flag=0;
    Pos e;
    Pos str[1000];
    L=(Strack)malloc(sizeof(LNode));
    L->Data=new char;
    L->Top=-1;
    cin>>str;
    for(i=0;str[i]!=0;i++)
      Push (L,str[i]);
    for(i=0;str[i]!=0;i++)
      Pop(L,e);
	  if(str[i]!=e){
	  	flag=1;
	  	
	   cout<<"no"<<endl;
	  } 
	  
	  else cout<<"yes"<<endl;
}
void  Push(Strack s,Pos t){
	s->Top++;
	s->Data[s->Top]=t;
	
}

void  Pop(Strack s,char &e){
	
	e=s->Data[s->Top];
	s->Top--;
}
