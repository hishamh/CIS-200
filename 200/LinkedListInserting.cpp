#include<iostream>

using namespace std;


template<class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};

template<class ItemType>

class Stack
{
private:
    NodeType<ItemType>* topPtr; // It points to a singly-linked list
public:
    Stack();  // default constructor: Stack is created and empty
    Stack(const Stack<ItemType> &x);  // copy constructor: implicitly called for a
    //  deep copy
    void MakeEmpty();    // Stack is made empty; you should deallocate all the
    //  the nodes of the linked list
    bool IsEmpty();// test if the stack is empty
    bool IsFull();   // test if the stack is full; assume MAXITEM=5
    int length();    // return the number of elements in the stack
    void Print();   // print the value of all elements in the stack in the sequence
    // from the top to bottom
    void Push(ItemType x);   // insert x onto the stack

    void Pop(ItemType &x);  // delete the top element from the stack
    // Precondition: the stack is not empty
    ~Stack();  // Destructor:  memory for nodes needs to be deallocated
};

template<class ItemType>
Stack<ItemType>::Stack()
{
    topPtr = NULL;
}

template<class ItemType>
Stack<ItemType>::Stack(const Stack<ItemType>&
                       x)
{
    //copy constrictor to so that can be coped to different variable
    NodeType<ItemType>* ptr1;
    NodeType<ItemType>* ptr2;

    //check if the root front is NULL
    if(x.topPtr == NULL)
        topPtr = NULL;
    else {
        topPtr = new NodeType<ItemType>;//create a node
        topPtr->info = x.topPtr->info;
        ptr1 = x.topPtr->next; //move ptr to the next node item
        ptr2 = topPtr;  //assign ptr2 to the head front root
        while(ptr1 !=NULL) {
            ptr2->next = new NodeType<ItemType>; //you create another nod to keep the information going and updating
            ptr2 = ptr2->next;
            ptr2->info = ptr1->info; //cotyp ptr2 info to by assigne by ptr1 info
            ptr1 = ptr1->next; //go to next
        }
        ptr2->next = NULL;
    }
}

template<class ItemType>
void Stack<ItemType>::MakeEmpty(){

    NodeType<ItemType>*current = topPtr;
    NodeType<ItemType>*temp;
    //will keep loop til current is NULL
    while(current != NULL)
    {
        temp = current; //copy value current to temp so that we can delete temp
        current = current->next;
        free(temp); //delete or remove
    }
}
template<class ItemType>
bool Stack<ItemType>::IsEmpty(){
    //check if front is Null to turn true or if not then it will be false
    if(topPtr == NULL)
        return true;
    else {
        return false; //if not null it will return false
    }
}
template<class ItemType>
bool Stack<ItemType>::IsFull(){
    //if the length was more then 5 then it will return false
    //else it will return ture
    if(length()==5){
        return true;
    }else{
        return false;
    }
}

template <class ItemType>
int Stack<ItemType>::length(){
    int length=0;
    NodeType<ItemType> *temp;
    temp = topPtr ;  //pointed to the first value
    while ( temp != NULL ) { //it will keep loop till the node have null
        length++; //increase the length to one value
        temp = temp->next;  //point to the next value
    }
    return length; //return length
}

template <class ItemType>
void Stack<ItemType>::Print(){

    NodeType<ItemType> *temp;
    temp = topPtr ;  //pointed to the first value
    while ( temp != NULL ) { //it will keep loop til the node have null
        cout<<temp->info<<endl;
        temp = temp->next;  //point to the nex value
    }

}

template <class ItemType>
void Stack<ItemType>::Push(ItemType item)
{
    NodeType<ItemType>* newNode;
    newNode = new NodeType<ItemType>; //create new node
    newNode->info = item; //assigned the newode to the item was entered
    newNode->next = topPtr; //assign the next toPtr to be NULL
    topPtr = newNode;
}

template <class ItemType>
void Stack<ItemType>::Pop(ItemType& item)
{

    NodeType<ItemType> *temp;
    //check if topPtr is null if it is then it is empty if not
    if(topPtr==NULL)
        cout << "Stack is empty";
    else {
    temp = topPtr;    //then assigne temp to head
    topPtr = topPtr->next; //then head  to head to go to next node and
    delete temp; //then delete the node or
    }

}

template<class ItemType>
Stack<ItemType>::~Stack()
{
    //delcar varabile temp
    NodeType<ItemType> *temp;
    NodeType<ItemType> *nodeToDelete;
    temp = topPtr;

    while(temp != NULL)
    {
        //it will keep loop till it goes to the next value and it will delete the next to the line
        temp = temp->next;
        nodeToDelete = temp; //save copy to nodeTodelete so that we can delete it
        delete nodeToDelete;
    }
}

int  main() {

    Stack <int> IntStack;
    int x;
    IntStack.Pop(x);  //delete
    IntStack.Push(11); //push it to linked list
    IntStack.Push(22);
    cout << "int length 1 = " << IntStack.length() << endl; //get the update length
    IntStack.Pop(x);        //delete the first element
    IntStack.Push(33);
    cout << "int length 2 = " << IntStack.length() << endl;
    cout << "The int stack contains : " << endl;
    IntStack.Print();
    IntStack.Push(44);
    IntStack.Push(55);
    IntStack.Push(66);
    if (IntStack.IsFull() == false)
        cout << "The int stack is not full !" << endl; //check if its full or not
    else
        cout << "The int stack is full !" << endl;
    Stack <int> IntStack2(IntStack);
    cout << "The int stack2 contains : " << endl;
    IntStack2.Print();
    IntStack2.MakeEmpty();
    cout << "The int stack3 contains : " << endl;
    IntStack2.Print();


    Stack <float> FloatStack;
    float y;
    FloatStack.Pop(y);
    FloatStack.Push(7.1);
    cout << "float length 1 = " << FloatStack.length() << endl;
    FloatStack.Push(2.3);
    FloatStack.Push(3.1);
    cout << "float length 2 = " << FloatStack.length() << endl;
    FloatStack.Pop(y);
    cout << "The float stack contains : " << endl;
    FloatStack.Print();
    Stack <float> FloatStack2 = FloatStack;
    cout << "The float stack 2 contains:  " << endl;
    FloatStack2.Print();
    FloatStack.MakeEmpty();
    cout << "The float stack 3 contains:  " << endl;
    FloatStack2.Print();

    return 0;
}
