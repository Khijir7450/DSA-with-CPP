#include <iostream>
using namespace std;
template <typename T>
class stackU_T
{
    T *data;
    int nextIndex;
    int capacity;

public:
    stackU_T();
    int size();
    bool isEmpty();
    void push(T);
    void pop();
    T top();
};
template <typename T>
stackU_T<T>::stackU_T()
{
    data = new T[5];
    nextIndex = 0;
    capacity = 5;
}
template <typename T>
void stackU_T<T>::push(T val)
{
    if (nextIndex == capacity)
    {
        T *newdata = new T[2 * capacity];
        for (int i = 0; i < capacity; i++)
        {
            newdata[i] = data[i];
        }
        delete[] data;
        data = newdata;
    }
    data[nextIndex] = val;
    nextIndex++;
}
template <typename T>
int stackU_T<T>::size()
{
    return nextIndex;
}
template <typename T>
bool stackU_T<T>::isEmpty()
{
    return nextIndex == 0;
}
template <typename T>
void stackU_T<T>::pop()
{
    if (isEmpty())
    {
        cout << "stack is Empty!!!!!" << endl;
    }
    else
    {
        nextIndex--;
        cout << "Delete:" << data[nextIndex] << endl;
    }
}
template <typename T>
T stackU_T<T>::top()
{
    if (isEmpty())
    {
        cout << "stack is Empty!!!!" << endl;
        return 0;
    }
    else
    {
        return data[nextIndex - 1];
    }
}
int main()
{
    stackU_T<char> s1;
    s1.push('X');
    s1.push('V');
    s1.push('I');
    s1.push('D');
    s1.push('E');
    s1.push('O');
    s1.push('S');
    // cout << "top element is:" << s1.top() << endl;
    // cout << "size of stack is:" << s1.size() << endl;
    s1.pop();
    s1.pop();
    s1.pop();
    cout << "top element is:" << s1.top() << endl;
    cout << "size of stack is:" << s1.size() << endl;
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();

    return 0;
}
