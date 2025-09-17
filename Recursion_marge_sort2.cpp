#include <iostream>
using namespace std;
void MargeArray(int A[], int si, int mid, int ei)
{
    int temp[ei + 1];
    int i = si;
    int j = mid + 1;
    int k = si;
    while (i <= mid && j <= ei)
    {
        if (A[i] <= A[j])
        {
            temp[k] = A[i];
            i++;
        }
        else
        {
            temp[k] = A[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = A[i];
        k++;
        i++;
    }
    while (j <= ei)
    {
        temp[k] = A[j];
        k++;
        j++;
    }

    for (int i = si; i <= ei; i++)
    {
        A[i] = temp[i];
    }
}
void Marge_sort(int A[], int si, int ei)
{
    int mid = (si + ei) / 2;
    if (si >= ei)
    {
        return;
    }
    Marge_sort(A, si, mid);
    Marge_sort(A, mid + 1, ei);
    MargeArray(A, si, mid, ei);
}
int main()
{
    int n;
    cout << "Enter size of array:";
    cin >> n;
    int A[n];
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
    int SI = 0;
    int EI = n - 1;
    Marge_sort(A, SI, EI);
    cout << endl
         << "array after sort:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}