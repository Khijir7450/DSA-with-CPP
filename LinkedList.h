#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val) : data(val), next(nullptr) {}
};

class LinkedList
{
private:
    node *sentinel; // dummy node

public:
    LinkedList()
    {
        sentinel = new node(-1); // sentinel data unused
        sentinel->next = nullptr;
    }

    // Insert into head
    void InsertAtHead(int val)
    {
        node *newNode = new node(val);
        newNode->next = sentinel->next;
        sentinel->next = newNode;
    }

    // Insert at tail
    void InsertAtTail(int val)
    {
        node *temp = sentinel;

        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new node(val);
    }
    // print List
    void PrintList()
    {
        node *temp = sentinel->next;
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    void DeleteHead()
    {
        if (sentinel)
        {
            sentinel->next = sentinel->next->next;
        }
        else
        {
            cout << "List is Empty." << endl;
        }
    }
    void DeleteTail()
    {
        if (sentinel)
        {
            node *temp = sentinel->next;
            node *prev = sentinel;

            while (temp->next)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
        }
        else
        {
            cout << "List is Empty." << endl;
        }
    }

    void DeleteVal(int val)
    {
        node *curr = sentinel->next;
        node *prev = sentinel;
        while ((curr))
        {
            if (curr->data == val)
            {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout<<val<<" not found at your Linked List."<<endl;
    }

    // Destructor
    ~LinkedList()
    {
        node *curr = sentinel;
        while (curr)
        {
            node *nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
    }
};