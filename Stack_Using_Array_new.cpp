#include <iostream>
using namespace std;

class stack
{
    int *data;
    int nextIndx;
    int capacity;

public:
    stack()
    {
        data = new int[5];
        nextIndx = 0;
        capacity = 5;
    }
    int size()
    {
        return nextIndx;
    }
    bool isEmpty()
    {
        /*
        if (nextIndx==0){
            return true;
        }
        else
        {
            return false;
        }
        */
        return nextIndx == 0;
    }
    //insert element
    void push(int element)
    {
        // if (nextIndx == capacity)
        // {
        //     cout << "stack if full!!!!!" << endl;
        // }
        // else
        // {
        //     data[nextIndx] = element;
        //     nextIndx++;
        // }

        if (nextIndx == capacity)
        {
            int *newData = new int(2 * capacity);
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity = 2 * capacity;
            delete[] data;
            data = newData;
        }

        data[nextIndx] = element;
        nextIndx++;
    }
    //delete element
    void pop()
    {
        if (isEmpty())
        {
            cout << "stack is empty!!!!!" << endl;
        }
        else
        {
            nextIndx = nextIndx - 1;
            cout << "delet:" << data[nextIndx] << endl;
        }
    }
    void top()
    {
        if (isEmpty())
        {
            cout << "stack is empty!!!!!" << endl;
        }
        cout << "top element is:" << data[nextIndx - 1] << endl;
    }
};
int main()
{
    stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);
    s1.push(70);
    s1.top();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    // s1.pop();
    // s1.pop();
    // s1.pop();
    cout << s1.size() << endl;
    cout << s1.isEmpty() << endl;

    return 0;
}