#include<bits/stdc++.h>
using namespace std;
bool isbalance(string expr){
    stack<char>s1;
    for(int i=0;i<expr.length();i++){
    if(s1.empty()){
        s1.push(expr[i]);
    }
    else if((s1.top()=='(' && expr[i]==')')||(s1.top()=='{'&& expr[i]=='}')||
    (s1.top()=='['&& expr[i]==']')){
        s1.pop();
    }
    else{
        s1.push(expr[i]);
    }
    }
    if(s1.empty()){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    string expression;
    cin>>expression;
    if(isbalance(expression)){
        cout<<"balanced"<<endl;
    }
    else{
        cout<<"not balanced"<<endl;
    }
    return 0;
}
