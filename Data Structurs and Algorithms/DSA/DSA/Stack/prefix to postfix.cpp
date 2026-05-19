#include<iostream>
using namespace std;
class Stack
{
public:
    int top;
    int size=100;
    string *arr;
    Stack()
    {
        arr=new string[size];
        top=-1;
    }
    void push(string s)
    {
        arr[++top]=s;
    }
    string peek()
    {
        if(top==-1)
        {
            return "Stack is empty";
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

};
void Connverttopostfix(string str)
{
    Stack s;
    for(int i=str.size()- 1;i>=0;i--)
    {
        char ch=str[i];
        if(isdigit(ch) || isalpha(ch))
        {
            s.push(string(1,ch));
        }
        else
        {
            string a=s.peek();
            s.pop();
            string b=s.peek();
            s.pop();
            string r=a+b+ch;
            s.push(r);
        }
    }
    cout<<s.peek();

}
int main()
{
    string name;
    cin>>name;
    Connverttopostfix(name);
}