#include <iostream>
using namespace std;

void BubbleSort(int* arr, int n);

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Here is your array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    BubbleSort(arr, n);

    cout << "Here is your sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}

void BubbleSort(int* arr, int n) {
    for(int i = 0; i < n-1; i++){
        bool flag = 0;
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        
        }
        if(flag == 0) break;
    }
}

/*
#include<iostream>
using namespace std;

void BubbleSort(int* arr, int n);

int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>> n;
    int *arr = new int[n];
    cout<<"Enter array element: ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];  
    }
    cout<<"Here is your array element: ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";  
    }
    cout<<endl;
    BubbleSort(arr,n);

    cout<<"Here is your Sorted array element: ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";  
    }





    delete [] arr;

}

void BubbleSort(int* arr, int n){



    // for (int i = 0; i < n - 1; i++) {
    //     bool swapped = false;
    //     for (int j = 0; j < n - i - 1; j++) {
    //         if (arr[j] > arr[j + 1]) { // ascending order
    //             int temp = arr[j];
    //             arr[j] = arr[j + 1];
    //             arr[j + 1] = temp;
    //             swapped = true;
    //         }
    //     }
    //     if (!swapped) break; // already sorted
    // }

    for(int i = 0; i >= n-1; i++){
        bool flag = 0;
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        
        }
        if(flag == 0) break;
    }

}
*/


