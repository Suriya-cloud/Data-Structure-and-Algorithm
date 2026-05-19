#include <iostream>
using namespace std;
class Stack{
	public:
	int top;
	char *arr;
	int size;
	Stack(){
		arr=new char[100];
		size=100;
		top=-1;
	}
	void push(char a){
		if(top==size-1){
			cout<<"Stack is full";
			return;
		}
		top++;
		arr[top]=a;
	}
	void pop(){
		if(top==-1){
			cout<<"Stack is empty";
			return;
		}
		top--;
	}
	char peek(){
		if(top==-1){
			cout<<"Stack empty";
			
		}
		return arr[top];

	}
	bool empty(){
		return top==-1;
	}
};
int precedence(char a){
	if(a=='+'||a=='-')return 1;
	if(a=='/'||a=='*')return 2;
}

void convertTopostfix(string str){
	string res="";
	Stack st;
	for(int i=0;i<str.size();i++){
		char ch=str[i];
		if(isdigit(ch)||isalpha(ch)){
			res+=ch;
		}
		else if(ch=='(' ){
			st.push(ch);
		}
		else if(ch == ')' ){
			while(!st.empty() && st.peek()!='(' ){
				res+=st.peek();
				st.pop();
			}
			st.pop();
		}else{
			while(!st.empty() && precedence(st.peek())>=precedence(ch)){
				res+=st.peek();
				st.pop();
			}
			st.push(ch);
		}
	}
		while(!st.empty()){
			res+=st.peek();
			st.pop();
		}
		cout<<res;


}

int main() 
{
	string s;
	cin>>s;
	convertTopostfix(s);
}