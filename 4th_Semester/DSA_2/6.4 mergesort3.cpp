#include <iostream>
using namespace std;

void showArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeArray(int arr[], int low, int mid, int high){
    int leftArraySize = mid-low+1;
    int rightArraySize = high-mid;

    int left_array[leftArraySize];
    int right_array[rightArraySize];

    for(int i=low;i<=mid;i++){
        left_array[i-low] = arr[i];
    }

    for(int i=mid+1;i<=high;i++){
        right_array[i-(mid+1)] = arr[i];
    }

    int leftArrayMarker = 0;
    int rightArrayMarker = 0;
    int arrayPos = low;

    while((leftArrayMarker<leftArraySize) && (rightArrayMarker<rightArraySize)){
                if(left_array[leftArrayMarker]>=right_array[rightArrayMarker]){
                    arr[arrayPos] = left_array[leftArrayMarker];
                    arrayPos++;
                    leftArrayMarker++;
                } else {
                    arr[arrayPos] = right_array[rightArrayMarker];
                    arrayPos++;
                    rightArrayMarker++;
                }
          }

    while(leftArrayMarker<leftArraySize){
        arr[arrayPos] = left_array[leftArrayMarker];
        arrayPos++;
        leftArrayMarker++;
    }

    while(rightArrayMarker<rightArraySize){
        arr[arrayPos] = right_array[rightArrayMarker];
        arrayPos++;
        rightArrayMarker++;
    }

}


void mergesort(int arr[], int low, int high){
    int mid = low + (high-low)/2;
    if(low<high){
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        mergeArray(arr, low, mid, high);
    }
}

int main()
{
    cout << "Enter size of array: " << endl;
    int n; cin>>n;
    int arr[n];
    cout << "Input array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Unsorted Array: ";
    showArray(arr, n);
    cout << endl;

    mergesort(arr, 0, n-1);

    cout << "Sorted Array: ";
    showArray(arr, n);
    cout << endl;
}

