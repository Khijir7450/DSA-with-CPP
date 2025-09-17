#include <iostream>
using namespace std;
int pertition(int *arr, int si, int ei)
{
    int pivot = arr[si];
    int pi = si;
    for (int i = si + 1; i <= ei; i++)
    {
        if (pivot > arr[i])
        {
            pi++;
        }
    }
    int temp = arr[pi];
    arr[pi] = arr[si];
    arr[si] = temp;
    int i = si, j = ei;
    while (i < pi && pi < j)
    {
        if (arr[i] > arr[pi] && arr[j] < arr[pi])
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        else if (arr[i] < arr[pi])
        {
            i++;
        }
        else
            j--;
    }
    return pi;
}
void Quick_Sort(int *arr, int si, int ei)
{
    if (si < ei)
    {
        int pi = pertition(arr, si, ei);
        Quick_Sort(arr, si, pi);
        Quick_Sort(arr, pi + 1, ei);
    }
    return;
}
int main()
{
    int n;
    cout << "Enter size of Array:";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter Array element:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Quick_Sort(arr, 0, n - 1);
    cout << "After sort your Array element is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}