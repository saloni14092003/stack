#include<bits/stdc++.h>
using namespace std;
bool isbalance(string expr){
    stack<char>s1;
    char x;
    for(int i=0;i<expr.length();i++){
        if(expr[i]=='{'||expr[i]=='['||expr[i]=='('){
            s1.push(expr[i]);
            continue;
        }
        if(s1.empty())
            return false;
    switch(expr[i]){
    case ')':
        x=s1.top();
        s1.pop();
        if(x=='{'||x=='[')
        return false;
        break;
    case '[':
        x=s1.top();
        s1.pop();
        if(x=='{'||x=='(')
        return false;
        break;  
    case '}':
        x=s1.top();
        s1.pop();
        if(x=='['||x=='(')
        return false;
        break;
    }
    }
return (s1.empty());
}
int main(){
    string expression="[][(a+b))";
    if(isbalance(expression)){
        cout<<"balanced";
    }
    else{
        cout<<"unbalance";
    }
    return 0;
}
