#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node*next;
}*top=NULL;
void push(int x){
    struct Node*t;
    t=new Node;
    if(t==NULL){
        cout<<"sttack overflow";
    }
    else{
    t->data=x;
    t->next=top;
    top=t;
    }
}
int pop(){
    struct Node*p;
    int x=-1;
    if(top==NULL){
        cout<<"stack underflow"<<endl;
    }
    else{
        p=top;
        top=top->next;
        x=p->data;
        delete(p);
    }
return x;
}
int peek(int pos){
  struct Node*p=top;
    for(int i=0;i<pos-1 && p;i++){
        p=p->next;
    }
    if (p!=NULL)
       return p->data;
    return -1;
}
int top_elem(){
    if(top){
        return top->data;
    }
    else{
        return -1;
    }
}
int isempty(){
    if(top==NULL)
       return 1;
    return 0;
}
int isfull(){
    struct Node*t;
    t=new Node;
    if(t==NULL)
       return 1;
    return 0;
}
void display(){
    struct Node*p;
    p=top;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
}
int main(){
    push(10);
    push(90);
    push(30);
    push(50);
    cout<<"the poped element is. "<<pop()<<endl;
    cout<<"the peek element is. "<<peek(3)<<endl;
    cout<<"the top element is. "<<top_elem()<<endl;
    display();
    return 0;
}
