#include <iostream>

using namespace std;

class stack{
	public:
	int size;
	char* arr;
	int top;
	stack(){
		size = 100;
		arr = new char[size];
		top = -1;
	}

	void push(char a){
		arr[++top]=a;
	}

	void pop(){
		top-=1;
	}

	char peek(){
		return arr[top];
	}

	bool isempty(){
		return top==-1;
	}
};

class Stack{
	public:
	int size;
	string* arr;
	int top;
	Stack(){
		size = 100;
		arr = new string[size];
		top = -1;
	}

	void push(string a){
		arr[++top]=a;
	}

	void pop(){
		top-=1;
	}

	string peek(){
		return arr[top];
	}

	bool isempty(){
		return top==-1;
	}
};

class valueStack{
	public:
	int size;
	int* arr;
	int top;
	valueStack(){
		size = 100;
		arr = new int[size];
		top = -1;
	}

	void push(int a){
		arr[++top]=a;
	}

	void pop(){
		top-=1;
	}

	int peek(){
		return arr[top];
	}

	bool isempty(){
		return top==-1;
	}
};

class operatorStack{
	public:
	int size;
	char* arr;
	int top;
	operatorStack(){
		size = 100;
		arr = new char[size];
		top = -1;
	}

	void push(char a){
		arr[++top]=a;
	}

	void pop(){
		top-=1;
	}

	char peek(){
		return arr[top];
	}

	bool isempty(){
		return top==-1;
	}
};

int solve(int a, int b, char o){
	if(o=='+') return a+b;
	if(o=='-') return a-b;
	if(o=='*') return a*b;
	if(o=='/') return a/b;
	return 0;
}

int presedence(char ch){
	if(ch=='+' || ch=='-') return 1;
	if(ch=='*' || ch=='/') return 2;
	return 0;
}

void convertInorderToPrefix(string s){
	stack st;
	string rev = "";
	for (int i=0; i<s.length(); i++){
		rev=s[i]+rev;
	}
	for (int i=0; i<rev.length(); i++){
		if(rev[i]=='('){
			rev[i]=')';
		}
		else if(rev[i]==')'){
			rev[i]='(';
		}
	}
	string res = "";
	for (int i=0; i<rev.length(); i++){
		if(isalpha(rev[i]) || isdigit(rev[i])){
			res+=rev[i];
		}
		else if(rev[i]=='('){
			st.push(rev[i]);
		}
		else if(rev[i]==')'){
			while(!st.isempty() && st.peek()!='('){
				res+=st.peek();
				st.pop();
			}
			st.pop();
		}
		else{
			while(!st.isempty() && presedence(st.peek())>=presedence(rev[i])){
				res+=st.peek();
				st.pop();
			}
			st.push(rev[i]);
		}
	}
	while(!st.isempty()){
		res+=st.peek();
		st.pop();
	}
	string ans="";
	for(int i=0; i<res.length(); i++){
		ans=res[i]+ans;
	}
	cout<<ans<<endl;
}

void convertInorderToPostfix(string s){
	stack str;
	string res = "";
	for(int i=0; i<s.length(); i++) {
		if(isdigit(s[i]) || isalpha(s[i])){
			res+=s[i];
		}
		else if(s[i]=='('){
			str.push(s[i]);
		}
		else if(s[i]==')'){
			while(!str.isempty() && str.peek()!='('){
				res+=str.peek();
				str.pop();
			}
			str.pop();
		}
		else{
			while(!str.isempty() && presedence(str.peek())>=presedence(s[i])){
				res+=str.peek();
				str.pop();
			}
			str.push(s[i]);
		}
	}
	while(!str.isempty()){
		res+=str.peek();
		str.pop();
	}
	cout<<res<<endl;
}

void convertPrefixToInfix(string s){
	Stack st;
	for(int i=s.length()-1; i>=0; i--){
		if(isdigit(s[i]) || isalpha(s[i])){
			st.push(string(1, s[i]));
		}
		else{
			string a = st.peek();
			st.pop();
			string b = st.peek();
			st.pop();
			string res="("+a+s[i]+b+")";
			st.push(res);
		}
	}
	cout<<st.peek()<<endl;
}

void convertPrefixToPostfix(string s){
	Stack str;
	for (int i=s.length()-1; i>=0; i--){
		if(isdigit(s[i]) || isalpha(s[i])){
			str.push(string(1, s[i]));
		}
		else{
			string a = str.peek();
			str.pop();
			string b = str.peek();
			str.pop();
			string res=a+b+s[i];
			str.push(res);
		}
	}
	cout<<str.peek()<<endl;
}

void convertPostfixToInfix(string s){
	Stack st1;
	for(int i=0; i<s.length(); i++){
		if(isdigit(s[i]) || isalpha(s[i])){
			st1.push(string(1, s[i]));
		}
		else{
			string a = st1.peek();
			st1.pop();
			string b = st1.peek();
			st1.pop();
			string res="("+b+s[i]+a+")";
			st1.push(res);
		}
	}
	cout<<st1.peek()<<endl;
}

void convertPostfixToPrefix(string s){
	Stack str1;
	for(int i=0; i<s.length(); i++){
		if(isdigit(s[i]) || isalpha(s[i])){
			str1.push(string(1, s[i]));
		}
		else {
			string a = str1.peek();
			str1.pop();
			string b = str1.peek();
			str1.pop();
			string res = s[i]+b+a;
			str1.push(res);
		}
	}
	cout<<str1.peek()<<endl;
}

void evaluationinfix(string s){
	valueStack value;
	operatorStack op;
	for(int i=0; i<s.length(); i++){
	if(isdigit(s[i])){
		value.push(s[i]-'0');
	}
	else if(s[i]=='('){
		op.push(s[i]);
	}
	else if(s[i]==')'){
		while(!op.isempty() && op.peek()!='('){
			char o=op.peek();
			op.pop();
			int b=value.peek();
			value.pop();
			int a=value.peek();
			value.pop();
			int res = solve(a, b, o);
			value.push(res);
		}
		op.pop();
	}
	else {
		while(!op.isempty() && presedence(op.peek())>=presedence(s[i])){
			char o=op.peek();
			op.pop();
			int b=value.peek();
			value.pop();
			int a=value.peek();
			value.pop();
			int res = solve(a, b, o);
			value.push(res);
		}
		op.push(s[i]);
		
	}
	}
	while(!op.isempty()){
			char o=op.peek();
			op.pop();
			int b=value.peek();
			value.pop();
			int a=value.peek();
			value.pop();
			int res = solve(a, b, o);
			value.push(res);
		}
		cout<<value.peek();

}



bool validParantahais(string s){
	operatorStack op1;
	for (int i=0; i<s.length(); i++){
		if(s[i]=='(' || s[i]=='{' || s[i]=='['){
			op1.push(s[i]);
		}
	else{
		if(op1.peek()=='(' && s[i]==')' || op1.peek()=='{' && s[i]=='}' || op1.peek()=='[' && s[i]==']'){
			op1.pop();
		}
		else{
			return false;
		}
	}
	}
	if(op1.isempty()){
	return true;
	}
	return false;
}


int main() 
{
	string s;
	cin>>s;
	//convertInorderToPrefix(s);
	//convertInorderToPostfix(s);
	//convertPrefixToInfix(s);
	//convertPrefixToPostfix(s);
	//convertPostfixToInfix(s);
	//convertPostfixToPrefix(s);
	//evaluationinfix(s);
	//evaluationprefix(s);
	//evaluationpostfix(s);
	if(validParantahais(s)){
		cout<<true;
	}
	else{
		cout<<false;
	}
}