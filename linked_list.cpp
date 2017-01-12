#include<iostream>
#include<stdio.h> 
#include<stdlib.h>
using namespace std;
struct node {
	int data;
	struct node * next;
} *head;
  
int count() {
  struct node * n;
  int c = 0;
  n = head;
  while (n != NULL) {
    n = n -> next;
    c++;
  }
  return c;
}

void append(int num) {
  struct node * temp, * right;
  temp = (struct node * ) malloc(sizeof(struct node));
  temp -> data = num;
  right = (struct node * ) head;
  while (right -> next != NULL)
    right = right -> next;
  right -> next = temp;
  right = temp;
  right -> next = NULL;
}

void add(int num) {
  struct node * temp;
  temp = (struct node * ) malloc(sizeof(struct node));
  temp -> data = num;
  if (head == NULL) {
    head = temp;
    head -> next = NULL;
  } else {
    temp -> next = head;
    head = temp;
  }
}

void addafter(int num, int loc) {
  int i;
  struct node * temp, * left, * right;
  right = head;
  for (i = 1; i <= loc; i++) {
    left = right;
    right = right -> next;
  }
  temp = (struct node * ) malloc(sizeof(struct node));
  temp -> data = num;
  left -> next = temp;
  left = temp;
  left -> next = right;
  return;
}

int ddelete_val(int num) {
  struct node * temp, * prev;
  temp = head;
  while (temp != NULL) {
    if (temp -> data == num) {
      if (temp == head) {
        head = temp -> next;
        return 1;
      } else {
        prev -> next = temp -> next;
        free(temp);
        return 1;
      }
    } else {
      prev = temp;
      temp = temp -> next;
    }
  }
  return 0;
}

void delete_occurence(int num) {
  struct node * n;
  int c = 1;
  n = head;
  while (n != NULL) {
  		ddelete_val(num);
    n = n -> next;
    c++;
  }
}

void insert(int num) {
  int c = 0;
  struct node * temp;
  temp = head;
  if (temp == NULL) {
    add(num);
  } else {
    while (temp != NULL) {
        c++;
      temp = temp -> next;
    }
    append(num);
  }
}

void display(struct node * r) {
  r = head;
  if (r == NULL) {
    return;
  }
  while (r != NULL) {
    printf("%d ", r -> data);
    r = r -> next;
  }
  printf("\n");
}

void search(int val) {
  struct node * n;
  int c = 1;
  n = head;
  while (n != NULL) {
  	if(n->data==val){
  		printf("Location of %d: %d\n",val,c);
	  }
    n = n -> next;
    c++;
  }
}

void reverse(){
	int num, reversedNumber = 0, remainder;

    while(num != 0)
    {
        remainder = num%10;
        reversedNumber = reversedNumber*10 + remainder;
        num /= 10;
    }

    cout << "Reversed List = " << reversedNumber;
}

int main() {
  int i, num,loc;
  struct node * n;
  head = NULL;

  while (1) {
  	system("cls");
    cout<<"Linked List Operations\n";
    cout<<"===============\n";
    cout<<("1.Insert\n");
    cout<<("2.Add after\n");
    cout<<("3.Display\n");
    cout<<("4.Size\n");
    cout<<("5.Delete\n");
    cout<<("6.Delete Occurence\n");
    cout<<("7.Search\n");
    cout<<("8.Reverse\n");
    cout<<("9.Exit\n");
    cout<<("Enter your choice : ");
    if (cin>>i <= 0) {
      cout<<("Enter only an Integer\n");
      exit(0);
    } else {
      switch (i) {
      case 1:
        cout<<("Enter the number to insert : ");
        cin>>num;
        insert(num);
        cout<<("Element(s) in the list are : ");
        display(n);
        break;
      case 2:
      	cout<<("Enter the number to insert : ");
        cin>>num;
        cout<<("Enter where to insert the number : ");
        cin>>loc;
        addafter(num,loc);
        cout<<("Element(s) in the list are : ");
        display(n);
      	break;
      case 3:
        if (head == NULL) {
          cout<<("List is Empty\n");
        } else {
          cout<<("Element(s) in the list are : ");
        }
        display(n);
        break;
      case 4:
        cout<<("Size of the list is ")<< count();
        break;
      case 5:
        if (head == NULL)
          cout<<("List is Empty\n");
        else {
          cout<<("Enter the number to delete : ");
          cin>>num;
          if (ddelete_val(num))
            cout<<num<<(" deleted successfully\n");
          else
            cout<<num<<(" not found in the list\n");
            cout<<("Element(s) in the list are : ");
            display(n);
        }
        break;
      case 6:
      	cout<<("Enter value to delete: ");
      	cin>>num;
        delete_occurence(num);
        cout<<("Element(s) in the list are : ");
        display(n);
        break;
      case 7:
	cout<<("Enter value to search: ");
      	cin>>num;
        search(num);
        break;
      case 8:
      	reverse();
      case 9:
      	return 0;
      default:
        cout<<("Invalid option\n");
      }
    }
      system("pause");
  }
  return 0;
}
