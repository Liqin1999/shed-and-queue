#include <stdio.h>
#include<stdlib.h>
#include<string.h>
void MainFum(char*a,int lenth);
int compare(char a,char b);
int IsNum(char c);
int Inop(char c);
int main() {
    char a[21];//���ʽ������20���ַ�
    scanf("%s",a);
    int len=strlen(a);

    MainFum(a,len);
    return 0;
}

int IsNum(char c) {
    return (c>='0'&&c<='9')||c=='.';
}
int Inop(char c) {
    return c=='+'||c=='-';
}

int compare(char a,char b) {
    if(b==')')return 1;
    if(a=='('||b=='(')return 0;

    switch(b) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            switch(a) {
                case '+':
                case '-':
                    return 0;
                case'*':
                case'/':
                    return 1;
            }
    }
}
void MainFum(char*a,int lenth) {
    static char stack[21];
    static int flag=0;//ָʾջ��
    static int i=0;//��̬�ֲ����������ڱ�ǵ�ǰ�����ַ�������һ��λ��
    static int space =0;

    for(; i<lenth; i++) {
        if(IsNum(a[i])) {
            if(space) {
                printf(" ");
                space =0;
            }
            printf("%c",a[i]);

        } else if(Inop(a[i])&&(i?!IsNum(a[i-1])&&a[i-1]!=')':1)) {
            if(a[i]=='-') {
                if(space) {
                    printf(" ");
                    space =0;
                }
                printf("%c",a[i]);//���Ų����
            }
        } else { //һ�����

            if(flag) {
                if(a[i]==')')
                    while(flag--) {
                        if(stack[flag]=='(')break;
                        printf(" %c",stack[flag]);
                    }
                else {
                    while(flag) {
                        if(compare(stack[flag-1],a[i])) {
                            printf(" %c",stack[--flag]);
                        } else break;
                    }
                    stack[flag++]=a[i];
                }

            } else stack[flag++]=a[i];
            for(int j=0; j<flag; j++)
                if(stack[j]!='(') {
                    space=1;
                    break;
                }
        }
    }
    while(flag) {
        printf(" %c",stack[--flag]);
    }

}
