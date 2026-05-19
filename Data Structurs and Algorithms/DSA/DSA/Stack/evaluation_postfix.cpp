#include <iostream>
using namespace std;
class Stack{
public:
    int top;
    int *arr;
    int size;
    Stack(){
        arr=new int[100];
        size=100;
        top=-1;
    }
    void push(char c){
        if(top==size-1){
            cout<<"Stack is full";
            return;
        }
        top++;
        arr[top]=c;
    }
    void pop(){
        if(top==-1){
            cout<<"Stack is empty";
            return;
        }
        top--;
    }
    int peek(){
        if(top==-1){
            cout<<"Stack is empty";
            return 0;
        }
        return arr[top];

    }
    bool empty(){
        return top==-1;
    }
};
void PostfixEvaluation(string str){
    Stack s;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(isdigit(ch)){
            s.push(ch-'0');
        }
        else if(ch=='+'||ch=='-'||ch=='/'||ch=='*'){
            int b=s.peek();
            s.pop();
            int a=s.peek();
            s.pop();
            int res=0;
            switch(ch){
                case '+':
                    res=a+b;
                    break;
                case '-':
                    res=a-b;
                    break;
                case '*':
                    res=a*b;
                    break;
                case '/':
                    res=a/b;
            }
            s.push(res);
        }
    }
    cout<<s.peek();
}
int main(){
    string str;
    cin>>str;
    PrefixEvaluation(str);
}

























