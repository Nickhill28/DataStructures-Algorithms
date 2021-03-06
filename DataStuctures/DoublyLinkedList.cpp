#include<bits/stdc++.h>
using namespace std;
//structure of Node with prev and next pointers
struct node {
int data;
struct node * prev;
struct node * next;
}*head, *last;


void createList(int n)
{
int i, data;
struct node *tobeadded;
if(n >= 1)
{
head = (struct node *)malloc(sizeof(struct node));

cin>> data;

head->data = data;
head->prev = NULL; // HEAD nodes's prev is set to NULL
head->next = NULL; // HEAD nodes's next is set to NULL
last = head;
for(i=2; i<=n; i++)
{
tobeadded = (struct node *)malloc(sizeof(struct node));
cin>>data;
tobeadded->data = data;
tobeadded->prev = last; // Link new node with the previous node
tobeadded->next = NULL;
last->next = tobeadded; // Link previous node with the new node
last = tobeadded; // Make new node as last node
}}}

void displayList()
{
struct node * temp;
int n = 1;
if(head == NULL)
cout<<endl<<"List is empty"<<endl;
else
{
temp = head;
cout<<endl<<"THE DOUBLY LINKED LIST IS :"<<endl<<endl;
// Print the list
while(temp != NULL)
{
cout<<temp->data<<"\t";
n++;
/* Move the current pointer to next node */
temp = temp->next;
}}}

/* Function to insert node at the beginning of the list */
void addonbegofDLL(int data)
{
struct node * newNode;
if(head == NULL)
cout<<"Error, List is Empty!"<<endl;
else
{
newNode = (struct node *)malloc(sizeof(struct node));
newNode->data = data;
newNode->next = head; // Point to next node which is currently head
newNode->prev = NULL; // Previous node of first node is NULL
/* Link previous address field of head with newNode */
head->prev = newNode;
/* Make the new node as head node */
head = newNode;
}
}

void addonEndofDLL(int data)
{
struct node * newNode;
if(last == NULL)
cout<<"Error, List is empty!";
else
{
newNode = (struct node *)malloc(sizeof(struct node));
newNode->data = data;
newNode->next = NULL;  // next pointer of newNode is NULL
newNode->prev = last;  // prev pointer of newNode is referenced to the last node
last->next = newNode; // next pointer of the last node is referenced to the newNode
last = newNode;  // newNode is made as the last node
}
}

void addatspecifiedinDLL(int data, int position)
{
int i;
struct node * newNode, *temp;
if(head == NULL)
cout<<"Error, List is empty!";
else
{
temp = head;
i=0;
while(i<position-1 && temp!=NULL)
{
temp = temp->next;
i++;
}
if(temp!=NULL)
{
newNode = (struct node *)malloc(sizeof(struct node));
newNode->data = data;
newNode->next = temp->next; // Connect new node with n + 1th node
newNode->prev = temp; // Connect new node with n - 1th node
if(temp->next != NULL)
{
/* Connect pos+1th node with new node */
temp->next->prev = newNode;
}
/* Connect pos-1th node with new node */
temp->next = newNode;
}
else
cout<<endl<<"Error, Invalid position"<<endl;
}}

void deleteBegofDLL()
{ 
 // Empty List
 if(head == NULL) 
 cout<<"\n The list is Empty\n"; 
 struct node *temp;
 temp = head; //Make temp as head node
 head = head -> next; // Shift the head node
 free(temp); // Delete the temporary node
}

void deleteEndofDLL()
{
// Empty List
if(head -> next == NULL)
{
free(head); //Delete head
head = NULL; // make the reference to NULL
}
struct node *temp = head,*prev_node;
while(temp -> next != NULL)
{
prev_node = temp;
temp = temp -> next; //Traverse to to the last node
}
free(temp); //Delete the last node
prev_node -> next = NULL;
}

void deleteatspecifiedofDLL(int pos)
{
// Empty List
if(head == NULL)
{
free(head); //Delete head
head = NULL; // make the reference to NULL
}
struct node *temp = head,*prev_node;
int count = 0;
while(temp -> next != NULL && pos != count)
{
prev_node = temp;  // Tracking the (position - 1 )node
temp = temp -> next; 
count = count + 1;
}
if(pos == count)
{
prev_node -> next = temp -> next;  // Assigning the address of the node to be deleted to its previous node
free(temp); // Delete the node
}
}


int main()
{
int n, data, choice=1;
head = NULL;
last = NULL;
cout<<endl<<"Enter the total number of nodes in list : "; // Input the number of nodes
cin>>n;
createList(n);
displayList();

int options=0;

while(options>=0){
cout<<endl<<endl<<"select where to insert if wanna insert"<<endl;
cout<<"1.Insert node at beginning"<<endl;
cout<<"2.Insert node at end "<<endl;
cout<<"3.Insert node at specific position"<<endl;
cout<<"4.Delete node at beginning"<<endl;
cout<<"5.Delete node at end "<<endl;
cout<<"6.Delete node at specific position"<<endl;
cout<<endl<<"Enter -1 if you dont want to modify DLL anymore"<<endl<<endl;

cin>>options;

if(options == 1){
cout<<endl<<endl<<"Enter data to be inserted at the beginning : ";
cin>>data;
addonbegofDLL(data);
displayList();
}

else if(options == 2){
cout<<"Enter data to be inserted at Last : ";
cin>>data;
addonEndofDLL(data);
displayList();

}

else if(options == 3){
int pos;
cout<<endl<<endl<<"Enter data to be inserted: ";
cin>>data;
cout<<endl<<"Enter the specific position : ";
cin>>pos;
addatspecifiedinDLL(data, pos-1);
displayList();

}

else if(options == 4){
  deleteBegofDLL();
  displayList();
}

else if(options == 5){
  deleteEndofDLL();
  displayList();
}

else if(options == 6){
  int pos;
  cout<<"\nEnter the position of node to be deleted: ";
  cin>>pos;
  deleteatspecifiedofDLL(pos-1);
  cout<<endl;
  displayList();
}
else{
cout<<endl<<"we are existing you Invalid response";
break;
}
}
return 0;
}
//
