#include <bits/stdc++.h>
 
using namespace std;
 
//Declare Node 
struct Node{
    int num; //store the data in the list position
    Node *next; //pointer to point who is next in the list
};
 
//Declare starting (Head) node
struct Node *head=NULL;
 
//Insert node at start
void insert(int n){
    struct Node *newNode=new Node; //creating a new node to be added in the list
    newNode->num=n; //add the data in the list
    newNode->next=head; //assigning the data to point to the previous head
    head=newNode; // assigning newNode to be the new Head
}
//inserting node at any position in a LL
void insertat(int nayanode,int isposition){
  struct Node *temp=new Node;//new temporary node
  temp->num=nayanode;//data in temp node
  temp->next= NULL;//pointing temp to null
  //if empty LL
  if(head==NULL){
    if(isposition == 0)
    head=temp;//temp is the new head of the LL
    else
    return;
  }
  //non Empty LL but insert at beginning
  if(head!=0 && isposition==0){
    temp->next = head;//temp pointing to head
    head=temp;//temp is the new head
    return;
  }
  struct Node *current=head;//current parser on head node
  struct Node *previous=NULL;//previous to current node for now initially null
  //iterating from starting to end of LL to find and insert at specific position
  for(int i=0;i<isposition;i++){
    previous = current;//previous is now current
    current = current->next;//current is now next to current
    //we have parsed one element and moved one step forward
    if(current == NULL)
    break;// current will be null when we reach the End of LL thus we get out
  }
  temp->next = current;//temp should now point to current
  previous->next = temp;//and previous will point temp
  //as they both make way for temp to be between them
}
//delete the node in LL at any position
//head pointer to access the LL and position to delete the specified position 
void deletethat(struct Node **heady,int positron){
  //empty LL eat 5star do nothing
  if(*heady == NULL)
  return;
  struct Node* deli = *heady;//new node deli to reference thy to be deleted lets initially point it to head
  //if have to delete at the beginning 
  if(positron == 0){
    *heady = deli->next;//head points to deli nodes next
    free(deli);//freeing memory of deli which was initially the head node
    return;
  }
  //parsing from start to last of the LL
  for (int i=0; deli!=NULL && i<positron-1; i++) 
  deli = deli->next; //moving the position to be deleted forward while we not match with the posistion
  //if we reach the end of LL w/o finding the position 
  if (deli == NULL || deli->next == NULL) 
  return;
  //creating a node to point the next of which is to be deleted.
  struct Node *delinext = deli->next->next;
  free(deli->next);//freeing memory of deli and its next pointer.
  deli->next=delinext;//now next to the previous of deli will be delinext which we defined to be deli's next. 
}
//Traverse/ display all nodes (print items)
void traverse_LL(){
    if(head==NULL){
        cout<<"Headless Linked List (MT list)!"<<endl;
        return;
    }
    struct Node *temp=head; //pointer ptr to head or to the first position of the list
    cout<<endl<<"Head ->";
    while(temp!=NULL){
        cout<<temp->num<<" ->";//print the data at ptr position
        temp=temp->next;//after that ptr is moved to the next position
    }
    cout<<" Tail";
    cout<<endl;
}
 
int main(){
     
    traverse_LL();
    cout<<endl<<"creating the Linked List";
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insertat(60,2);
    traverse_LL();
    cout<<endl<<"We now have a Linked List with a Head and a Tail";
    cout<<endl<<"Enter the number hit enter enter the position to insert"<<endl;
    int a,b;
    cin>>a>>b;
    insertat(a,b);
    traverse_LL();
    int d;
    cout<<endl<<"wanna delete something"<<endl;
    cin>>d;
    deletethat(&head,d);
    traverse_LL();
    return 0;
}
