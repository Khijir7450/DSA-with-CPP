#include <iostream>
#include <vector>
using namespace std;

tuple<bool, vector<int>, int> is_K_present(int *arr, int n, int k);

int main()
{
    // taking input from user, like array size, array element, number which have to find.
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
         << "Enter which you want to find me in the array: ";
    cin >> K;

    tuple<bool, vector<int>, int> t = is_K_present(arr, n, K);
    bool found = get<0>(t);
    vector<int> indices = get<1>(t);
    int count = get<2>(t);

    cout << "Found: " << found << endl;
    cout << "how many time found: " << count << endl;

    if (found)
    {
        cout << "Indices of " << K << ": ";
        for (int i = 0; i < indices.size(); i++)
        {
            cout << indices[i] << " ";
        }
    }

    delete[] arr;
    return 0;
}


// is_K_present() return the element found or not, indices where the
//  element found and how many time found.

tuple<bool, vector<int>, int> is_K_present(int *arr, int n, int k)
{

    bool isPresent = false;
    vector<int> index_Of_K;

    int countOfK = 0;
    for (int i = 0; i < n; i++)
    {
        if (k == arr[i])
        {
            isPresent = true;
            index_Of_K.push_back(i);
            countOfK++;
        }
    }

    return {isPresent, index_Of_K, countOfK};
}