#include<bits/stdc++.h>
using namespace std;


struct Node{
  int data;
  struct Node *next;
};


struct Node *addinMTCLL(struct Node *tail,int tobeadded){
  if(tail != NULL)
  return tail;

  struct Node *Twelthman = (struct Node*)malloc(sizeof(struct Node));
  Twelthman->data=tobeadded;
  tail = Twelthman;
  tail->next = tail;

  return tail;

}

struct Node *addatbegCLL(struct Node *end,int tobeadded){
  if(end==NULL)
  return addinMTCLL(end,tobeadded);

  struct Node *Twelthman = (struct Node*)malloc(sizeof(struct Node));

  Twelthman->data=tobeadded;
  Twelthman->next=end->next;
  end->next=Twelthman;

  return end;

}

struct Node *addendofCLL(struct Node *end,int tobeadded){
  if(end==NULL)
  return addinMTCLL(end,tobeadded);

  struct Node *Twelthman = (struct Node*)malloc(sizeof(struct Node));

  Twelthman->data=tobeadded;
  Twelthman->next=end->next;
  end->next=Twelthman;
  end=Twelthman;

  return end;
}

struct Node *addhereinCLL(struct Node *last,int tobeadded,int position){
  if(last==NULL)
  return addinMTCLL(last,tobeadded);
  else if(position==1)
  return addatbegCLL(last,tobeadded);
  else{
  struct Node *Twelthman = (struct Node*)malloc(sizeof(struct Node));
  struct Node *current;

  Twelthman->data=tobeadded;
  current = last->next;

  for(int i=2; i<=position-1; i++)
  current = current->next;

  /* Links new node with node ahead of it and previous to it*/
  Twelthman->next = current->next;
  current->next = Twelthman;

  return last;
  }
}

struct Node *pluckitoutCLL(struct Node *last,int tobeplucked)
{
  struct Node *prev,*curr;//defining the previous and the current nodes
  int count;//counting the number of nodes present
  
  //if the list is empty
  if(last->next == NULL)
  return 0;
  count=0;
  curr = last->next;//current is head
  prev = curr;//previous is current all in all we have nothing.

  //while current is not head
  while (prev->next != last->next){
    prev = prev->next;//iterate to next element
    count++;//increase count of node by one.
  }

  int i = 0;//loop variable for the following: while variable is less than or equal to the number of nodes present
  while(i<=count)
  {
    //if the data to be deleted is matched in the circular linkedlist
    if (curr->data == tobeplucked)
    {
      //if the CLL has more than one elements in it
      if(curr->next != curr)
      prev->next = curr->next;//previous will be followed by current nodes next node as we will delete current

      else
      prev->next = NULL;//there was one element that will also be deleted making the CLL empty
      
      //if current is at the head position of CLL
      if(curr == last->next)
      last->next = prev->next;// head will be equal to next node of previous of current.

      free(curr);//freeing memory space of current
      
      //if not a single element CLL
      if(prev != NULL)
      curr = prev->next;//current will be iterated to the next node of the previous one.

      else
      curr = NULL;//there is no current as it was deleted
    }
    //if data to be deleted is not matched in the CLL
    else
    {
    prev = curr;//previous will be current
    curr = curr->next;//current will be iterated to next
    }
    i++;//increment the loop variable by one
  }
  return last;//return the modified CLL
}

void traverseCLL(struct Node *last) 
{ 
  struct Node *p; 
  
  // If list is empty, return. 
  if (last == NULL) 
  { 
    cout << "List is empty." << endl; 
    return; 
  } 
  
  // Pointing to first Node of the list. 
  p = last -> next; 
  
  // Traversing the list. 
  //cout<<"begining is the end ->";
  do
  { 
    cout <<p -> data << " "; 
    p = p -> next; 
  
  }while(p != last->next); 
  //cout<<"begining is the end";
  
} 

int main() 
{ 
  struct Node *last = NULL; 
  
  last = addinMTCLL(last, 2); 
  last = addatbegCLL(last, 1); 
  last = addatbegCLL(last, 8); 
  last = addendofCLL(last, 5); 
  last = addendofCLL(last, 4); 
  last = addendofCLL(last, 2); 
  last = addendofCLL(last, 1);
  last = addendofCLL(last, 2); 
  last = addendofCLL(last, 1);
  last = addhereinCLL(last, 6, 4); 
  
  traverseCLL(last); 

  cout<<endl<<"The owner of this list is herself so circular."<<endl;

  cout<<endl<<endl;

  int deleteit;
  cout<<"which One you want to delete specify dont write the position "<<endl;
  cin>>deleteit;

  last = pluckitoutCLL(last, deleteit);

  traverseCLL(last);

  cout<<endl<<"Wow! now we've lost her contact... \n cheers doing PnC to find the deleted digits."<<endl;
  
  return 0; 
} 
