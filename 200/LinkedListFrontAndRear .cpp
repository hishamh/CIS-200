/*
  main.cpp
  proj 3 questin 2

    This teach us how to create node linked list and use rear and front to
    access data

  Created by Hisham on 11/26/17.
  Copyright © 2017 Hisham Hussein. All rights reserved.
*/

#include <iostream>
using namespace std;

//constructor node that will create information to
template<class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};

template<class ItemType>
class Queue
{
private:
    NodeType<ItemType>* front; // It points to the front of a singly-linked list
    NodeType<ItemType>* rear; // It points to the end of a singly-linked list

public:
    Queue( );  // default constructor: Queue is created and empty
    Queue(const Queue<ItemType> &x);  // copy constructor: implicitly called
    // for a deep copy
    void MakeEmpty();    // Queue is made empty; you should deallocate all
    //  the nodes of the linked list
    bool IsEmpty( );   // test if the queue is empty
    bool IsFull( );   // test if the queue is full; assume MAXITEM=5
    int length( );    // return the number of elements in the queue
    void Print( );   // print the value of all elements in the queue in the sequence
    // from the front to rear
    void Enqueue(ItemType x);   // insert x to the rear of the queue
    // Precondition: the queue is not full
    void Dequeue(ItemType &x);  // delete the element from the front of the queue
    // Precondition: the queue is not empty
    ~Queue();  // Destructor:  memory for the dynamic array needs to be deallocated
};


template<class Type>

Queue<Type>::Queue()
{
    front = NULL;
    rear = NULL;
}

template<class ItemType>
Queue<ItemType>::Queue(const Queue<ItemType> &x)

{
    //copy constrictor to so that can be coped to different variable
    NodeType<ItemType>* ptr1;
    NodeType<ItemType>* ptr2;

    //check if the root front is NULL
    if(x.front == NULL)
        front = NULL;
    else {
        front = new NodeType<ItemType>; //create a node
        front->info = x.front->info;
        ptr1 = x.front->next; //move ptr to the next node item
        ptr2 = front; //assigne ptr2 to the head front root
        while(ptr1 !=NULL) {
            ptr2->next = new NodeType<ItemType>; //you create another nod to keep the information going and updating
            ptr2 = ptr2->next; //ptr2 will go to the next pointer
            ptr2->info = ptr1->info; //ptr2 will store the information in ptr1 info
            ptr1 = ptr1->next; //it will grip the next value in ptr1
        }
        ptr2->next = NULL;
        rear = ptr2;
    }

}

template<class ItemType>
void Queue<ItemType>::MakeEmpty(){

    NodeType<ItemType>*current = front;
    NodeType<ItemType>*temp;
    //will keep loop til current is NULL
    while(current != NULL)
    {
        temp = current; //copy value current to temp so that we can delete temp
        current = current->next;
        free(temp);  //delete or remove
    }
}
template<class ItemType>
bool Queue<ItemType>::IsEmpty(){
    //check if front is Null to turn true or if not then it will be false
    if(front == NULL)
        return true;
    else {
        return false;
    }
}
template<class ItemType>
bool Queue<ItemType>::IsFull(){
    //if length equal 5 then its the limited to say its true or if not 5 then its false
    if(length()==5){ //if its equal 5 then it will turn true
        return true;
    }else{
        return false; //if not equal to 5 then it will turn false
    }
}

template <class ItemType>
int Queue<ItemType>::length(){
    int length=0;
    NodeType<ItemType> *temp;
    temp = front ;  //pointed to the first value
    while ( temp != NULL ) { //it will keep loop till the node have null
        length++;
        temp = temp->next;  //point to the next value
    }
    return length; //return length
}
template <class ItemType>
void Queue<ItemType>::Print(){

    NodeType<ItemType> *temp;
    temp = front ;  //pointed to the first value
    while ( temp != NULL ) { //it will keep loop till the node have null
        cout<<temp->info<<endl;
        temp = temp->next;  //point to the next value
    }

}

template <class ItemType>
void Queue<ItemType>::Enqueue(ItemType item)
{

    NodeType<ItemType>* newNode;
    newNode = new NodeType<ItemType>; //create a node
    //assigine the node the value to be save to info
    newNode->info=item;
    newNode->next=NULL; //next move will be NULL the node that will be app

    /*check if the root front is not equal null then we assign next to
     location value then we rear to location to hold the data
     */
    if(front!=NULL)
    {
        rear->next=newNode; //if the front is not empty then assign end the rear to newnode
        rear=newNode;
    }
    else
    {

        front=newNode; //if  empty then assign  front to newNode and also at
        rear=newNode;//the end to newNode
        newNode=NULL;
    }
}

template <class ItemType>
void Queue<ItemType>::Dequeue(ItemType& item)
{
    NodeType<ItemType> *temp;

    //delete the fron of the list from the node so we start wit the head
    if(front==NULL)
        cout << "Stack is empty";
    else {
        temp = front; //now assign temp to front
        front = front->next; //it go to the next value and assign the next head
        delete temp; //deleting the first head
    }
}

template<class ItemType>
Queue<ItemType>::~Queue()
{
    NodeType<ItemType> *temp;
    NodeType<ItemType> *nodeToDelete;
    temp = front;

    //it will keep loop till it goes to the next value and it will delete the next to the line
    while(temp != NULL)
    {
        temp = temp->next;
        nodeToDelete = temp; //save copy to nodeTodelete so that we can delete it
        delete nodeToDelete;
    }
}

int main(){
Queue<int>IntQueue;
int x;
IntQueue.MakeEmpty(); //it delete everything
IntQueue.Dequeue(x); //delete the first head
IntQueue.Enqueue(10); //inserting to the list
IntQueue.Enqueue(20);
IntQueue.Enqueue(30);
IntQueue.Enqueue(40);
cout << "int length 3 = " << IntQueue.length() << endl; //check the length
IntQueue.Dequeue(x);
cout << "int length 4 = " << IntQueue.length() << endl; //check the length
cout << "The int queue contains:  " << endl;
IntQueue.Print();  /// print the list
if(IntQueue.IsFull() == false) //check if the list is full or not
cout << "The int queue is not full !" << endl;
else
cout << "The int queue is full !" << endl;

Queue<float>FloatQueue;
float y;
FloatQueue.MakeEmpty();
FloatQueue.Dequeue(y);
FloatQueue.Enqueue(7.1);
cout << "float length 3 = " << FloatQueue.length() << endl;
FloatQueue.Enqueue(2.3);
cout << "float length 4 = " << FloatQueue.length() << endl;
FloatQueue.Enqueue(3.1);
FloatQueue.Dequeue(y);
cout << "The float queue contains:  " << endl;
FloatQueue.Print();
Queue<float> FloatQueue2 = FloatQueue;
cout << "The float queue 2 contains:  " << endl;
FloatQueue2.Print();
FloatQueue.MakeEmpty();
cout << "The float queue 3 contains:  " << endl;
FloatQueue2.Print();

    return 0;
}
