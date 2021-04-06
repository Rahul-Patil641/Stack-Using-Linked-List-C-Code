#include<iostream>
#include<cstring>
using namespace std;
template <typename T>
struct Node
{
    T data;

    Node<T>* next;
    Node()
    {
        //data = 0;
        next = NULL;
    }
    Node(T d)
    {
        data = d;
        next = NULL;
    }
};
template <typename T>
class Stack
{
private:
    Node<T>* top;
    int count;
    int max_size;
public:
    T element;
    Stack();
    Stack(int c);
    void push(T data);
    bool isFull();
    bool isEmpty();
    T pop();
    T peep();
    void display();
    int counts();
    Node<T>* getNode(T data);
};

template <typename T>
Stack<T> ::Stack()
{
    max_size = 0;
}
template<typename T>
Stack<T>::Stack(int c)
{
    max_size = c;
    top = NULL;
    count = 0;
}

template <typename T>
bool Stack<T>::isEmpty()
{
     if(top==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <typename T>
bool Stack<T>::isFull()
{
    if(count==max_size)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template <typename T>
Node<T>* Stack<T>::getNode(T d)
{
    Node<T>* temp = new Node<T>;
    temp->data = d;
    //temp->next = NULL;
    return temp;
}
template<typename T>
void Stack<T>::push(T data)
{
    Node<T> * new_node = getNode(data);

    //Checking if the stack is empty.
    if(isEmpty())
    {
        top = new_node;
        count++;
        cout<<"Node added Successfully!!"<<endl;
    }
    //Checking if the stack is full.
    else if(isFull())
    {
        cout<<"Stack Overflow"<<endl;
    }
    else
    {
        new_node->next = top;
        top = new_node;
        count++;
        cout<<"Node PUSHED successfully"<<endl;
    }
}
template <typename T>
T Stack<T>::pop()
{
    Node<T>* temp = NULL;
    T d = top->data;
    if(isEmpty())
    {
        cout<<"STACK underflow"<<endl;
        return 0;
    }
    else if(top->next==NULL)
    {
        temp = top;
        top = NULL;
        delete temp;
        count--;
        cout<<"Node popped successfully! Now Stack underflow"<<endl;
    }
    else
    {
        temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
        count--;
        cout<<"Node popped successfully"<<endl;
    }
    return d;
}
template <typename T>
T Stack<T>::peep()
{
    T d = top->data;
    if(isEmpty())
    {
        cout<<"STACK underflow"<<endl;
        return 0;
    }
    else
    {
        return d;
    }
}
template <typename T>
void Stack<T>::display()
{
    if(isEmpty())
    {
        cout<<"Stack Underflow"<<endl;
        cout<<"No values to display"<<endl;
    }
    else
    {
        Node<T>* temp = top;
        cout<<"All values in the stack are:"<<endl;
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp = temp->next;
        }

    }
}
template <typename T>
int Stack<T>::counts()
{
    return count;
}


int main()
{
    int Data,Max,option;
    cout<<"Enter the maximum size of the stack:"<<endl;
    cin>>Max;
    Stack<int> s(Max);
    do{
        cout<<"Which Operation do you want to perform? Enter an option number! Press 0 to exit."<<endl;
        cout<<"1. To push an element"<<endl;
        cout<<"2. To pop the topmost element"<<endl;
        cout<<"3. To peep the topmost element in the stack"<<endl;
        cout<<"4. To display the Stack elements"<<endl;
        cout<<"5. To display the number of elements in the stack"<<endl;
        cout<<"6. To check whether the Stack is empty or not"<<endl;
        cout<<"7. To check whether the Stack is Full or not"<<endl;
        cin>>option;

        switch(option)
        {
        case 0:
            cout<<"THANK YOU"<<endl;
            break;
        case 1:
            cout<<"Enter the data to pushed"<<endl;
            cin>>s.element;
            s.push(s.element);
            break;
        case 2:
            cout<<"Pop Function called"<<endl;
            cout<<"Popped element: "<<s.pop()<<endl;
            break;
        case 3:
            cout<<"Peep Function called"<<endl;
            cout<<"Topmost element: "<<s.peep()<<endl;
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout<<"Number of Elements in the stack: "<<s.counts()<<endl;
            break;
        case 6:
            if(s.isEmpty())
            {
                cout<<"The Stack is Empty"<<endl;
                break;
            }
            else
            {
                cout<<"Stack is not empty"<<endl;
                break;
            }
            break;
        case 7:
            if(s.isFull())
            {
                cout<<"Stack is Full"<<endl;
                break;
            }
            else
            {
                cout<<"Stack is not Full"<<endl;
                break;
            }
            break;
        default:
            cout<<"Enter a Valid Option Number"<<endl;
        }
    }while(option!=0);
    return 0;
}
