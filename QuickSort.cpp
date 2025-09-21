#include <iostream>
using namespace std;

int Partition(int* arr, int l, int r){
    int pivot = arr[l];
    int start = l+1;
    int end = r;

    while(start<end){
        while(arr[start]<=pivot && start<=end){
            start++;
        }
        while(arr[end]>pivot && end>=start){
            end--;
        }
        if(start<end){
        swap(arr[start],arr[end]);
        }
    }
    swap(arr[l],arr[end]);
    return end;
}

void QuickSort(int* arr, int l, int r){
    if(l<r){
        int loc = Partition(arr,l,r);
        QuickSort(arr,l,loc-1);
        QuickSort(arr,loc+1,r);
    }
}

int Partitiondesc(int* arr, int l, int r){
    int pivot = arr[r];  
    int start = l;
    int end = r - 1;

    while (start <= end) {
        while (arr[start] > pivot) {
            start++;
        }
        while (end >= start && arr[end] <= pivot) {
            end--;
        }

        if (start < end) {
            swap(arr[start], arr[end]);
        }
    }
    swap(arr[start], arr[r]);
    return start;
}

void QuickSortdes(int* arr, int l, int r){
    if(l<r){
        int loc = Partitiondesc(arr,l,r);
        QuickSortdes(arr,l,loc-1);
        QuickSortdes(arr,loc+1,r);
    }
}

void Display(int* arr, int n){

    for(int i=0;i<n;i++){
        cout << arr[i] << endl;
    }
}

int main(){
    int n;
    cout << "Enter size of array:";
    cin >> n;

    int* arr = (int*)malloc(sizeof(int)*n);

    cout << "Enter elements of array:";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << "Quick sort in ascending order:";
    QuickSort(arr,0,n-1);
    Display(arr, n);

    cout << "Quick sort in descending order:";
    QuickSortdes(arr, 0, n-1);
    Display(arr, n);

    free(arr);
}
