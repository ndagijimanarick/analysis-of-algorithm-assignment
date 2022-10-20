#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <cstdlib>
using namespace std;
struct Node{
	int data;
	int key;
	struct Node *next;
};
	struct Node *head;
    struct Node *tail;

class SinglyLinkedList{
	
public:
    //default constructor to create empty list
    SinglyLinkedList(){
     Node *head=NULL;
     Node *tail=NULL;
     cout<<"Empty  list created!!!\n\n";
	}
	//copy constructor
      //SinglyLinkedList(const SinglyLinkedList & obj1) {
				//	head = obj1.head;
  				//	tail = obj1.tail;
  			//	}
  /*	void operator = (const SinglyLinkedList & l) {
 				 head = l.head;
 				 tail = l.tail;
}*/
		// Return the head of the linked list
	Node *getHead() {
  				return head;
}
		// Return tail of the linked list
	Node *getTail() {
 			 if (tail == NULL)
  				  return NULL;
 				 return tail;
}
	//Adding numbers into our linked list randomly
	void insertRandomly(int size){     
	struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode -> data=size;
	if(head==NULL){
		newNode -> next=NULL;
		head=newNode;
	}
	else{
		newNode->next=head;
		head=newNode;
	}
}

// Desctructor
  ~SinglyLinkedList() {
    Node * current = head;
    while (current != 0) {
      Node * next = current -> next;
      delete current;
      current = next;
    }
    head = NULL;
  } 
  
//Didplay list
void printList(){
	struct Node *ptr=head;
	cout<<"[";
	while(ptr !=NULL){
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<"]";
}

// using srand to use the function which will construct list randomly
 SinglyLinkedList(int size) {
    srand(time(0));
    for (int i = 0; i < size; i++){     
      insertRandomly(rand());	
	}
     
  }
  
  //This stage of inserting element at the front of list
  void insertAtBeginning(){
	int value;
	cout<<"\n\nEnter element at the front of linked list: ";
	cin>>value;
	struct Node *newNode;
	newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode -> data=value;
	if(head==NULL){
		newNode -> next=NULL;
		head=newNode;
	}
	else{
		newNode->next=head;
		head=newNode;
	}
	
}
  //This is for inserting element at the end of list
   void insertAtEnd(){
   	int value;
   	cout<<"\n\nInsert Elements at the end of list: ";
   	cin>>value;
 	struct Node *newNode;
 	newNode=(struct Node*)malloc(sizeof(struct Node));
 	newNode->data=value;
 	newNode->next=NULL;
 	if(head==NULL)
 		head=newNode;
	else{
		struct Node *temp=head;
		while(temp->next!=NULL)
		temp=temp->next;
		temp->next=newNode;
	}
 }
 
 //searching for a given number
     search(int val) {
 			 Node * temp = head;
 			 while (temp != NULL) {
   			 if (temp -> data == val) return true;
   			 
   						 temp = temp -> next;
}
  				return false;
}

    
 //Deleting item from list
 void deleteNumber(){
 	int pos;
 	cout<<"\n\nEnter the position where you want to delete:";
 	cin>>pos;
 	int i,flag=0;
 	struct Node *temp1=head, *temp2;
 	if(pos==1){
 		head=temp1->next;
 		free(temp1);
 		cout<<"\n number deleted \n";
	 }
	 else{
	 	for(i=0;i<pos-1;i++){
	 		if(temp1->next !=NULL){
	 			temp2=temp1;
	 			temp1=temp1->next;
			 }
			 else{
			 	flag=1;
			 	break;
			 }
		 }
		 if(flag==0){
		 	temp2->next=temp1->next;
		 	free(temp1);
		 	cout<<"Number is deleted\n\n";
		 }
		 else{
		 	cout<<"\nThe position of that number exceed linked list. Please try again!!!\n";
		 }
	 }
 }
 //reversing the the data of list
   void reverseList(){
	  struct Node *prevnode;
	  struct Node *currentnode;
	  struct Node *nextnode;
	  prevnode=0;
	  currentnode=nextnode=head;
	
	while(nextnode !=0){
		nextnode=nextnode->next;
		currentnode->next=prevnode;
		prevnode=currentnode;
		currentnode=nextnode;
	}
	head=prevnode;
}

//remove consecutive duplicates
        void removeDuplicate() {
  		this -> selectionSort();
 			 // temp pointing to head
 			 Node * temp = head;
  				while (temp -> next != NULL && temp != NULL) {
   			 // Duplicate Found
   					 if (temp -> data == temp -> next -> data) {
   	   // DUplicate Removed
    		  temp -> next = temp -> next -> next;
    } else {
      // No Duplicate Present
      temp = temp -> next;
    }
  }
}
  //sort the list 
 void selectionSort() {
 		 Node * temp = head;

  	// Traverse the List
  			while (temp) {
  			  Node * min = temp;
   				 Node * r = temp -> next;

    // Traverse the unsorted sublist
    while (r) {
      if (min -> data > r -> data) min = r;
      r = r -> next;
    }
    int x = temp -> data;
    temp -> data = min -> data;
    min -> data = x;
    temp = temp -> next;
  }
}

};

int main(){
	SinglyLinkedList obj3;
	SinglyLinkedList obj(5);
	SinglyLinkedList obj2=1;
	int val;
	obj.insertRandomly(6); //this will call function that construct linked list randomly
	cout<<"Elements of linked list constructed  Randomly are:\n";
	obj2.printList();
	
	obj2.insertAtBeginning(); //insert element at front
	cout<<"list after insertion at the beginning successfully:\n";
	obj2.printList();
	
	obj2.insertAtEnd(); //insert element at the end
	cout<<"list after insertion at the end successfully:\n";
	obj2.printList();
	
	obj2.deleteNumber(); //delete item at a given position
	cout<<"list after deleting an item:\n";
	obj2.printList();
	
	//here we are on reversing the list
	cout<<"\n\nThe list after reversing the data:\n";
	obj2.reverseList();
	obj2.printList();
	
	//this is for searching a number
	cout<<"\nSearch any number:";
	cin>>val;
	cout<<obj2.search(val);
	//sorted list
	obj2.selectionSort();
	cout<<"\nSorted list\n";
	obj2.printList();
	cout<<"\n";
	//find duplicates to remove
	obj2.removeDuplicate();
	cout<<"\nOur list after finding duplicates\n";
	obj2.printList();
	return 0;
}
//Time complexity of inserting at the front of linked list is O(1).
//Time complexity of inserting at the end of linked list is O(n).
//Time complexity of searching for a given number is O(n)
//Time complexity of Deleting a given number is O(1).
//Time complexity for reversing the list is O(n)
//Time complexity for remove consecutive duplicates is O(n^2) 
