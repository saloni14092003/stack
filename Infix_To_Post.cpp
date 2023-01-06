#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node*next;
}*top=NULL;
void push(int x){
    struct Node*t;
    t=new Node;
    if(t==NULL){
        cout<<"overflow";
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
int pop(){
    int x=-1;
    struct Node*t;
    t=top;
    if(top==NULL){
        cout<<"underflow";
    }
    else{
        top=top->next;
        x=t->data;
        delete(t);
    }
    return x;
}
int isoperand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='~'||x=='!'||x=='^'||x=='('||x==')')
       return 0;
    return 1;
}
int precedence(char x){
    if(x=='+'||x=='-')
    {
        return 1;
    }
    else if(x=='*'||x=='/'){
        return 2;
    }
   return 0;
}
char * IntoPost(char *infix){
    int i=0,j=0;
    char *postfix=new char(strlen(infix)+2);
    while(infix[i]!='\0'){
        if(isoperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else{
            if(precedence(infix[i])>precedence(top->data))
               push(infix[i++]);
            else
            postfix[j++]=pop();
        }
    }
    while(top!=NULL){
        postfix[j++]=pop();
        postfix[j]='\0';
    }
    return postfix;
}
void display(){
    struct Node*p;
    p=top;
    while(p){
        cout<<p->data;
        p=p->next;
    }
}
int main(){
    char *infix;
    cin>>infix;
    push('#');
    char *postfix= IntoPost(infix);
    cout<<postfix;
    return 0;
}
