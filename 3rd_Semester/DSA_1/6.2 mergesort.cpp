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

    // Copying elements into left_array
    for(int i=low;i<=mid;i++){
        left_array[i-low] = arr[i];
    }
    // Copying elements into right_array
    for(int i=mid+1;i<=high;i++){
        right_array[i-(mid+1)] = arr[i];
    }
    //for(int i=low;i<mid;i++)cout<<"la "<< left_array[i-low];
    //for(int i=mid+1;i<high;i++)cout<<"la "<< right_array[i];

    int leftArrayMarker = 0;
    int rightArrayMarker = 0;
    int arrayPos = low;

    while((leftArrayMarker<leftArraySize) && (rightArrayMarker<rightArraySize)){
                if(left_array[leftArrayMarker]>=right_array[rightArrayMarker]){
                    arr[arrayPos] = left_array[leftArrayMarker];
                    //cout << left_array[leftArrayMarker]<<endl;
                    arrayPos++;
                    leftArrayMarker++;
                } else {
                    arr[arrayPos] = right_array[rightArrayMarker];
                    //cout << right_array[rightArrayMarker]<<endl;
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
    int arr[] = {10, 3, 1, 5, 43, 49, 6, 7};

    int arr_len = sizeof(arr)/sizeof(arr[0]);

    //sortArray(arr, arr_len);
    cout << "Unsorted Array: ";
    showArray(arr, arr_len);
    cout << endl;

    mergesort(arr, 0, arr_len-1);

    cout << "Sorted Array: ";
    showArray(arr, arr_len);
    cout << endl;
}
