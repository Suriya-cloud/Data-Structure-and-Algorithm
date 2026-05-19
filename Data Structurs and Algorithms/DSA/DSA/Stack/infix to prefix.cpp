#include<iostream>
using namespace std;
class Stack
{
    public:
    int top;
    int size=100;
    char *arr;
    Stack()
    {
        arr=new char[size];
        top=-1;
    }
    void push(char s)
    {
        arr[++top]=s;
    }
    char peek()
    {
        if(top==-1)
        {
            cout<<"Stack is empty";
            return ' ';
        }
       return arr[top];
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack is empty";
            return ;
        }
        top=top-1;
    }
    bool isempty()
    {
        return (top==-1);
    }
    int precedence(char name)
    {
        if(name=='-'|| name=='+')return 1;
        if(name=='*'||name=='/')return 2;
        return 0;
    }
};
void Connverttoprefix(string str)
{
    string rev="";
    Stack s;
    for(int i=0;i<str.size();i++)
    {
        rev=str[i]+ rev;
    }
    str=rev;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
        {
            str[i]=')';
        }
        else if(str[i]==')')
        {
            str[i]='(';
        }
    }
    string res;
    for(int i=0;i<str.size();i++)
    {
        char ch=str[i];
        if(isdigit(ch)|| isalpha(ch))
        {
            res+=ch;
        }
        else if(ch=='(')
        {
            s.push(ch);
        }
        else if(ch==')')
        {
            while(!s.isempty() && s.peek()!='(')
            {
                res+=s.peek();
                s.pop();
            }
            s.pop();
        }
        else{
            while(!s.isempty() && s.precedence(s.peek())>s.precedence(ch))
            {
                res+=s.peek();
                s.pop();
            }
            s.push(ch);
        }
    }
        while(!s.isempty())
        {
            res+=s.peek();
            s.pop();
        }
        string ans="";
        for(int i=0;i<res.size();i++)
        {
            ans=res[i]+ans;
        }
        cout<<ans;
}
int main()
{
    string name;
    cin>>name;
    Connverttoprefix(name);
}