//trial lng
#include<iostream>
#include<string>
using namespace std;
string stack[40];
int top=-1;
void push(int a){
	top++;
	stack[top]=a;
}
int main(){
	char arr[40];
	string op, op1;
	cin>>arr;
	int p=strlen(arr);
	for(int i=0;i<p;i++)
	if(arr([i]=='+'||arr[i]=='-'||arr[i]=='*'||arr[i]=='/'){
		op=stack[top];
		top--;
		op1=stack[top];
		stack[top]=op1+arr[i]+op;
	}
	else
	push(arr[i]);
	cout<<"Infix = "<<stack[top]<<endl;
}
