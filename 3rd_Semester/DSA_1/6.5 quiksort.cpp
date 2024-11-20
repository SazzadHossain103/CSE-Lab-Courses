# include <iostream>
using namespace std;
// quick sort sorting algorithm
int Partition(int arr[], int st, int ed)
{
    int pivot = arr[st]; //arr[ed];
    int pIndex = st;

    for(int i = st; i<ed; i++)
    {
        if(arr[i]>pivot) //if(arr[i]<pivot) asseding order
        {
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }
    }

    int temp = arr[ed];
    arr[ed] = arr[pIndex];
    arr[pIndex] = temp;

    return pIndex;
}

void QuickSort(int arr[], int st, int ed)
{
    if(st<ed)
    {
        int p = Partition(arr,st, ed);
        QuickSort(arr, st, (p-1));  // recursive QS call for left partition
        QuickSort(arr, (p+1), ed);  // recursive QS call for right partition
    }
}

int main()
{

    cout<<"Enter Size of array: "<<endl;
    int n; cin>>n;
    int arr[n];

    cout<<"Input array: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Before Sorting"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    QuickSort(arr,0,(n-1));  // quick sort called

    cout<<"After Sorting"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
