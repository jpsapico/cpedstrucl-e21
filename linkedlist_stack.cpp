//stack with linked list
//dynamic
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

void display();
void push(int);
void pop();

struct node{
	int data;
	node *next;
}*top;

int main(){
	cout << "Stack array implementation using linked list\n";
	do{
		system("cls");
		int choice;
		cout << "STACK\n";
		cout << "[1]-Push \n";
		cout << "[2]-Pop \n";
		cout << "[3]-Traverse \n";
		cout << "[4]-Exit \n";
		cout << "Enter choice: ";
		cin >> choice;
		
		switch(choice){
			case 1:{
					int num;
					cout << "Enter n: ";
					cin >> num;
					push(num);
				} break;
			case 2:{
					pop();
				} break;	
			case 3:{
					display();
				} break;
			case 4:{
					exit(1);
				} break;
			default: cout << "Error!"; break;
		} getch();
	} while(1);
	getch();
	return 0;
}

void push(int n){
	node *p=new node;
	p->data=n;
	if(top==NULL){
		p->next=NULL;
	}
	else{
		p->next=top;
	}
	top=p;
}

void pop(){
	if (top==NULL){
		cout << "Stack is empty. ";
	}
	else{
		node *tmp=top;
		cout << "\nPopped value " << top->data << endl;
		top=top->next;
		tmp->next=NULL;
		delete(tmp);
	}
}

void display(){
	node *p;
	if (top==NULL){
		cout << "Empty";
	}
	else {
		cout << "STACK\n";
		cout << setw(10) << "POINTER "
			 << setw(10) << "VALUE"
			 << setw(10) << "NEXT"
			 << endl;
	}
	p=top;
	while(p!=NULL){
		cout << setw(10) << p
			 << setw(10) << p->data
			 << setw(10) << p->next
			 << endl;
			 p=p->next;
	}
}
