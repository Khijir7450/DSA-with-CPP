#include <iostream>
using namespace std;
int Pertition(int arr[], int si, int ei)
{
    int pivot = arr[si];
    int pindex = si;
    for (int i = si+1; i <= ei; i++)
    {
        if (pivot > arr[i])
        {
            pindex++;
        }
    }
    int temp = arr[pindex];
    arr[pindex] = arr[si];
    arr[si] = temp;
    int i = si;
    int j = ei;
    while (i < pindex && j > pindex)
    {
        if (arr[i] < arr[pindex])
        {
            i++;
        }
        if (arr[j] > arr[pindex])
        {
            j--;
        }
        if (arr[i] > arr[pindex] && arr[j] < arr[pindex])
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return pindex;
}
void QuickSort(int ar[], int si, int ei)
{
    if (si < ei)
    {
        int pi = Pertition(ar, si, ei);
        QuickSort(ar, si, (pi - 1));
        QuickSort(ar, (pi + 1), ei);
    }
    else
        return;
}
int main()
{
    int n;
    cout << "Enter size of array:";
    cin >> n;
    int A[50];
    cout << "enter array element:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << "your array before sort:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    QuickSort(A, 0, n - 1);
    cout << endl
         << "array after sort:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}