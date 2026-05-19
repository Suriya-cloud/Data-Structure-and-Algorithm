#include <iostream>
using namespace std;
class ValueStack{
	public:
	int top;
	int *arr;
	int size;
	ValueStack(){
		arr=new int[100];
		size=100;
		top=-1;
	}
	void push(int c){
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
class OperatorStack{
	public:
		int size;
		char *arr1;
		int top;
		OperatorStack(){
			size=100;
			arr1=new char[size];
			top=-1;
		}
		void push(char c){
		if(top==size-1){
			cout<<"Stack is full";
			return;
		}
		top++;
		arr1[top]=c;
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
		return arr1[top];

	}
	bool empty(){
		return top==-1;
	}

};

int solve(int a,int b,char c){
	if(c=='-')return a-b;
	if(c=='+')return a+b;
	if(c=='*')return a*b;
	if(c=='/')return a/b;
	return -1;
}
int precedence(char name)
    {
        if(name=='-'|| name=='+')return 1;
        if(name=='*'||name=='/')return 2;
        return 0;
    }

void evaluateInfix(string str){
	ValueStack values;
	OperatorStack optr;
	for(int i=0;i<str.size();i++){
		char ch=str[i];
		if(isdigit(ch)){
			int num=0;
			while(i<str.size() && isdigit(str[i])){
				num=num*10+str[i]-'0';
				i++;
			}
			values.push(num);
			i--;
		}
		else if(ch=='(' ){
			optr.push(ch);
		}
		else if(ch==')' ){
			while(!optr.empty() && optr.peek() != '(' ){
				char o=optr.peek();
				int b=values.peek();
				values.pop();
				int a=values.peek();
				values.pop();
				int res = solve(a,b,o);
				values.push(res);
			}
			optr.pop();
		}
		else{
			while(!optr.empty() &&  precedence(optr.peek())>=precedence(ch) ){
				char c=optr.peek();
				optr.pop();
				int b=values.peek();
				values.pop();
				int a=values.peek();
				values.pop();
				int res=solve(a,b,c);
				values.push(res);
			}
		}
	}
		while(!optr.empty()){
			char c=optr.peek();
			optr.pop();
			int b=values.peek();
			values.pop();
			int a=values.peek();
			values.pop();
			int res=solve(a,b,c);
			values.push(res);
		}
		cout<<values.peek();

}
int main(){
	string s;
	cin>>s;
	evaluateInfix(s);
}




























