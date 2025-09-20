#include <iostream>
#include <stdexcept>
using namespace std;

class node
{
private:
    int data;
    node *next;

public:
    node(int val)
    {
        this->data = val;
        this->next = nullptr;
    }

    friend class queue;
};

class queue
{
private:
    node *Head;
    node *Tail;
    int size;

public:
    queue()
    { // Constructor
        this->Head = nullptr;
        this->Tail = nullptr;
        size = 0;
    }
    ~queue()
    { // Destructor to free memory
        while (!isEmpty())
        {
            Dequeue();
        }
    }

    int Size()
    {
        return size;
    }
    bool isEmpty()
    {
        return Head == nullptr && Tail == nullptr;
    }
    void Enqueue(int val)
    {

        node *newNode = new node(val);
        if (Head == nullptr)
        {

            Head = newNode;
            Tail = newNode;
        }
        else
        {

            Tail->next = newNode;
            Tail = newNode;
        }
        size++;
    }
    int Dequeue()
    {
        if (isEmpty())
        {
            throw underflow_error("Queue Underflow: Cannot dequeue from an empty queue.");
        }

        int front = Head->data;
        node *temp = Head;
        Head = Head->next;
        if (Head == nullptr)
        { // if queue becomes empty
            Tail = nullptr;
        }

        delete temp;
        size--;
        return front;
    }

    int Peek()
    {
        if (isEmpty())
        {
            throw underflow_error("Queue is Empty: Don't have peek.");
        }
        return Head->data;
    }
};

int main()
{
    try
    {

        queue q;
        cout << "Initial Size: " << q.Size() << endl;
        // cout << "Dequeue on Empty queue: " << q.Dequeue() << endl;

        q.Enqueue(1);
        q.Enqueue(2);
        q.Enqueue(3);
        q.Enqueue(4);
        q.Enqueue(5);
        cout << "Size: " << q.Size() << endl;
        cout << "Peek : " << q.Peek() << endl;
        cout << "Size: " << q.Size() << endl;
        cout << "Dequeue: " << q.Dequeue() << endl;
        cout << "Size: " << q.Size() << endl;
        cout << "Peek : " << q.Peek() << endl;

        return 0;
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
}