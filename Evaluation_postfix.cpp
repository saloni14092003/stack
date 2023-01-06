#include <bits/stdc++.h>

using namespace std;
 struct Node{
     int data;
     struct Node*next;
 }*top=NULL;
int isoperand (int x){
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'||x==')'||x=='('||x=='!'||x=='~')
       return 0;
    return 1;
}
void push(int x){
    struct Node*t;
    t=new Node;
    if(t==0){
        cout<<"overflow";
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
int pop(){
    struct Node*t;
    int x=-1;
    if(top==NULL){
        cout<<"underflow";
    }
    else{
        t=top;
        top=top->next;
        x=t->data;
        delete(t);
    }
    return x;
}

int Evaluation(char postfix[]) {
    int i=0;
    int x1,x2,r=0;//x1 will store LHS & x2 RHS(first pop store at RHS)
    for(int i=0;postfix[i]!='\0';i++){
        if(isoperand(postfix[i])){
            push(postfix[i]-'0'); //subtract from 0 or 48
        }
        else{
            x2=pop();
            x1=pop();
            switch(postfix[i]){
                case '+':r=x1+x2;break;
                case '-':r=x1-x2;break;
                case '*':r=x1*x2;break;
                case '/':r=x1/x2;break;
            }
                push(r);
        }
    }
    return top->data; 
}
int main() {
    char* postfix[100];
   cin>>postfix[100];
   cout<<Evaluation(postfix[100]);
 return 0;
}
