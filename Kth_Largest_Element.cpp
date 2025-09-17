#include <iostream>
#include <climits>
using namespace std;

int Find_Kth_Largest(int *arr, int n, int k);

int main()
{

    int n;
    cout << "Enter the size of array- ";
    cin >> n;
    int *arr = new int[n];

    cout << endl;
    cout << "Enter the array element - ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int K;
    cout << endl
         << "Tell me which largest(Kth) number you wanna find: ";
    cin >> K;

    int KthlargestNum = Find_Kth_Largest(arr, n, K);

    cout << endl
         << "Kth largest element in the array is:- " << KthlargestNum;

    delete[] arr;
    return 0;
}


//as we instructed to do brute force approch, hence this function create a copy of user given array, 
//and find the maximun and change them too INT_MIN, for finding the Kth larget element
//This function not only return Kth Largest element But also print no of Comparison.

int Find_Kth_Largest(int *arr, int n, int k)
{

    int count = 0;

    int *copyArr = new int[n];
    for (int i = 0; i < n; i++)
    {
        copyArr[i] = arr[i];
    }

    int max;
    int maxIndex = -1;
    int i;
    while (k >= 1)
    {
        max = INT_MIN;
        for (i = 0; i < n; i++)
        {
            if (copyArr[i] > max)
            {
                max = copyArr[i];
                maxIndex = i;
            }
            count++;
        }
        copyArr[maxIndex] = INT_MIN;

        k--;
    }
    delete[] copyArr;
    cout << endl
         << "No of Comparison is:- " << count;
    return max;
}