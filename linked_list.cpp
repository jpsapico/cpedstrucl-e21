#include<iostream>
#include<conio.h>
using namespace std;

class LinkedList{
    struct Node {
        int x;
        Node *next;
        
    };

public:
    LinkedList(){
        head = NULL; // set head to NULL
    }

    void addValue(int number){
        Node *n = new Node();   
        n->x = number;             
        n->next = head;         
                               
        head = n;    
		
		          
    }

    int popValue(){
        Node *n = head;
        int ret = n->x;

        head = head->next;
        delete n;
        return ret;
        
    }
    
    void display(){
    int counter=1;
    temp=head;
    while(head!=0){
  	
    Node *n = head;
    int ret = n->x;
    head = head->next;
  	counter++;
    cout<<ret<<endl;
    }
    
    head=temp;
	}
	
	void Update(int counter,int number){
	cout<<"Update";
	cout<<"Enter position: ";
	cin>>counter;
	cout<<"Enter new number: ";
	cin>>number;
	
	
		
	}
	
    
private:
    Node *head; 
    Node *temp;
};

int main()
{
	LinkedList list;
	int choice,number,counter;
	while (1)
	{	
	system("cls");
	cout<<"        MENU"<<endl;
	cout<<"[1] Push"<<endl;
	cout<<"[2] Pop"<<endl;
	cout<<"[3] Display"<<endl;
	cout<<"[4] Update"<<endl;
	cout<<"[5] Exit"<<endl;
	cout<<"Enter your choice:";
	cin>>choice;
	switch(choice)
	{
	
		case 1:
			cout<<"Enter a number:";
			cin>>number;
			list.addValue(number);
			break;
			
		
		case 2:
		list.popValue();
		break;
		
		case 3:
		list.display();
		break;
		
		case 4:
			list.Update(counter,number);
			break;
		
		case 5:
			exit(1);
		
		default:
			cout<<"Error, Try again";
							
	}
	getch();
	}	
}
