#include<bits/stdc++.h>
using namespace std;

//structure of Node with prev and next pointers
struct node {
int data;
struct node * prev;
struct node * next;
}*head, *last;

int nodecount = 0;

class circulardoublylist {
  public:
    node *createDCLL(int);
    void addtoBegofDCLL();
    void addtoEndofDCLL();
    void addatPositioninDCLL();
    void deleteatPositioninDCLL();
    void displayDCLL();
    circulardoublylist() {
      head = NULL;
      last = NULL;
    }
};

//Create the DoublyCircular LinkedList with as many nodes as required.
node* circulardoublylist::createDCLL(int v) {
   nodecount++;
   struct node *t;
   t = new(struct node);//(struct node *)malloc(sizeof(struct node));
   t->data = v;
   t->next = NULL;
   t->prev = NULL;
   return t;
}

//insert at the beginning of the Doublycircular LinkedList
void circulardoublylist::addtoBegofDCLL() {
   int v;
   cout<<endl<<"Enter the element to be inserted: ";
   cin>>v;
   struct node *temp;
   temp = createDCLL(v);
   if (head == last && head == NULL) {
      cout<<"Element inserted in empty list"<<endl;
      head = last = temp;
      head->next = last->next = NULL;
      head->prev = last->prev = NULL;
   } else {
      temp->next = head;
      head->prev = temp;
      head = temp;
      head->prev = last;
      last->next = head;
      cout<<"Element inserted"<<endl;
   }
}

void circulardoublylist::addtoEndofDCLL() {
   int v;
   cout<<endl<<"Enter the element to be inserted: ";
   cin>>v;
   struct node *temp;
   temp = createDCLL(v);
   if (head == last && head == NULL) {
      cout<<"Element inserted in empty list"<<endl;
      head = last = temp;
      head->next= last->next = NULL;
      head->prev = last->prev= NULL;
   } else {
      last->next= temp;
      temp->prev= last;
      last = temp;
      head->prev = last;
      last->next= head;
   }
}

void circulardoublylist::addatPositioninDCLL() {
   int v, pos, i;
   cout<<endl<<"Enter the element to be inserted: ";
   cin>>v;
   cout<<endl<<"Enter the position of element inserted: ";
   cin>>pos;
   struct node *temp, *start, *ptr;
   temp = createDCLL(v);
   if (head == last && head == NULL) {
      if (pos == 1) {
         head = last = temp;
         head->next = last->next = NULL;
         head->prev = last->prev = NULL;
      } else {
         cout<<"Position out of range"<<endl;
         nodecount--;
         return;
      }
   } else {
      if (nodecount < pos) {
         cout<<"Position out of range"<<endl;
         nodecount--;
         return;
      }
      start = head;
      for (i = 1;i <= nodecount;i++) {
         ptr = start;
         start = start->next;
         if (i == pos - 1) {
            ptr->next = temp;
            temp->prev= ptr;
            temp->next= start;
            start->prev = temp ;
            cout<<"Element inserted"<<endl;
            break;
         }
      }
   }
}

void circulardoublylist::deleteatPositioninDCLL() {
   int pos, i;
   node *ptr, *start;
   if (head == last && head  == NULL) {
      cout<<"List is empty, nothing to delete"<<endl;
      return;
   }
   cout<<endl<<"Enter the position of element to be deleted: ";
   cin>>pos;
   if (nodecount < pos) {
      cout<<"Position out of range"<<endl;
      return;
   }
   start = head ;
   if(pos == 1) {
      nodecount--;
      last->next = start->next;
      start->next->prev = last;
      head = start->next;
      free(start);
      cout<<"Element Deleted"<<endl;
      return;
   }
   for (i = 0;i < pos - 1;i++ ) {
      start = start->next;
      ptr = start->prev;
   }
   ptr->next = start->next;
   start->next->prev = ptr;
   if (pos == nodecount) {
      last = ptr;
   }
   nodecount--;
   free(start);
   cout<<"Element Deleted"<<endl;
}

void circulardoublylist::displayDCLL() {
   int i;
   struct node *start;
   if (head == last && head == NULL) {
      cout<<"The List is empty, nothing to display"<<endl;
      return;
   }
   start = head;
   for (i = 0;i < nodecount-1;i++) {
      cout<<start->data<<" <=> ";
      start = start->next;
   }
   cout<<start->data<<endl;
}

int main() 
{
  int c;
  circulardoublylist dcll;
  while (1) {//perform switch operation {
    cout<<"1.Insert at Beginning"<<endl;
    cout<<"2.Insert at End"<<endl;
    cout<<"3.Insert at Position"<<endl;
    cout<<"4.Delete at Position"<<endl;
    cout<<"5.Display List"<<endl;
    cout<<"6.Exit"<<endl;
    cout<<"Enter your choice : ";
    cin>>c;
    switch(c) {
      case 1:
        dcll.addtoBegofDCLL();
        break;
      case 2:
        dcll.addtoEndofDCLL();
        break;
      case 3:
        dcll.addatPositioninDCLL();
        break;
      case 4:
        dcll.deleteatPositioninDCLL();
        break;
      case 5:
        dcll.displayDCLL();
        break;
      case 6:
        exit(1);
      default:
        cout<<"Wrong choice"<<endl;
    }
  }
  return 0;
}
