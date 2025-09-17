#include <iostream>
using namespace std;
template <typename T>
class node
{
public:
    T data;
    node<T> *next;

public:
    node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
template <typename T>
class stack
{
    node<T> *head;
    int size;

public:
    stack();
    void push(T element);
    void getsize();
    bool isEmpty();
    void pop();
    void top();
};
template <typename T>
stack<T>::stack()
{
    head = NULL;
    size = 0;
}
template <typename T>
void stack<T>::push(T element)
{
    node<T> *newNode = new node<T>(element);
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
template <typename T>
bool stack<T>::isEmpty()
{
    return size == 0;
}
template <typename T>
void stack<T>::pop()
{
    if (isEmpty())
    {
        cout << "stack is Empty!!!!" << endl;
    }
    else
    {
        cout << "delet:" << head->data << endl;
        node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
    }
}
template <typename T>
void stack<T>::top()
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
template <typename T>
void stack<T>::getsize()
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
    stack<int> s1;
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
    stack<float> s2;
    s2.push(10.5);
    s2.push(20.5);
    s2.push(30.5);
    s2.push(40.5);
    s2.getsize();
    s2.top();
    cout << "stack is Empty(1) or not(0): " << s2.isEmpty() << endl;
    s2.pop();
    s2.pop();
    s2.pop();
    s2.pop();
    s2.top();
    cout << "stack is Empty(1) or not(0): " << s2.isEmpty() << endl;

    return 0;
}