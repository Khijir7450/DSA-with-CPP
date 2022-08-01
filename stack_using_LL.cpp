#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

public:
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class stack
{
    node *head;
    int size;

public:
    stack();
    void push(int element);
    void getsize();
    bool isEmpty();
    void pop();
    void top();
};
stack::stack()
{
    head = NULL;
    size = 0;
}
void stack::push(int element)
{
    node *newNode = new node(element);
    if (head == NULL)
    {
        head = newNode;
        size++;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        size++;
    }
}
bool stack::isEmpty()
{
    return size == 0;
}

void stack::pop()
{
    if (isEmpty())
    {
        cout << "stack is Empty!!!!" << endl;
    }
    else
    {
        cout << "delet:" << head->data << endl;
        node* temp=head;
        head = head->next;
        delete temp;
        size--;
    }
}

void stack::top()
{
    if (isEmpty())
    {
        cout << "stack is Empty!!!!" << endl;
    }
    else
    {
        cout << "Top element is:" << head->data << endl;
    }
}
void stack::getsize()
{
    if (isEmpty())
    {
        cout << "stack is Empty!!!" << endl;
    }
    else
    {
        cout << "stack size is:" << size << endl;
    }
}

int main()
{
    stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.getsize();
    s1.top();
    cout<<"stack is Empty(1) or not(0): "<<s1.isEmpty()<<endl;
    s1.pop();
    s1.getsize();
    s1.top();

    return 0;
}