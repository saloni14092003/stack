#include <bits/stdc++.h>
using namespace std;
struct Stack{
    int size;
    int top;
    int *s;
};
void create(struct Stack*st){
    cout<<"enter size"<<" ";
    cin>>st->size;
    int top=-1;
    st->s=new int(st->size);
}
void push(struct Stack *st,int x){
    if(st->top==st->size){
        cout<<"stack overflow"<<" ";
    }
    else{
        st->top++;
        st->s[st->top]=x;
    }
}
int pop(struct Stack*st){
    int x=-1;
    if(st->top==-1){
        cout<<"stack underflow"<<" ";
    }
    else{
        x=st->s[st->top--];
    }
    return x;
}
int peek(struct Stack st,int index){
    int x=-1;
    if(st.top-index+1<0)
       cout<<"invalid index"<<" ";
    else{
       x=st.s[st.top-index+1];
    }
    return x;
}
int isempty(struct Stack st){
    if(st.top==-1)
      return 1;
    return 0;
}
int isfull(struct Stack st){
    if(st.top>=st.size-1)
       return 1;
    return 0;
}
int stackTop(struct Stack st){
    if(!isempty(st)){
        return st.s[st.top];
    }
    else{
        return -1;
    }
}
void display(struct Stack st){
    for(int i=st.top;i>=0;i--){
        cout<<st.s[i]<<" ";
    }
}
int main(){
    struct Stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    cout<<stackTop(st)<<endl;
    return 0;
}

