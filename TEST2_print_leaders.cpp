#include <iostream>
using namespace std;
void printArray(int arr[], int n)
{
    cout << "Your array is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void CheckAndLeader(int arr[], int n)
{
    bool leader = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] >= arr[j])
            {
                leader = true;
                continue;
            }
            else
            {
                leader = false;
                break;
            }
        }
        if (leader == true)
        {
            cout <<arr[i] << " ";
        }
    }
}
int main()
{
    int arr[100];
    int n;
    cout << "Enter size of array:";
    cin >> n;
    cout << "Enter array element:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    printArray(arr, n);
     CheckAndLeader(arr, n);
  /*  bool leader = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] >= arr[j])
            {
                leader = true;
                continue;
            }
            else
            {
                leader = false;
                break;
            }
        }
        if (leader == true)
        {
            cout << i << " ";
        }
    }*/
}