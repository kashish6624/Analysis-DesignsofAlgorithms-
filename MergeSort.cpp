#include <iostream>
using namespace std;

void Merge(int arr[], int l,int r, int mid) {
    if (l >= r) {
        return;
    }

    int s1 = mid - l + 1; 
    int s2 = r - mid;

    int left[s1];
    int right[s2];

    for (int i = 0; i < s1; i++) {
        left[i] = arr[i + l];
    }

    for (int j = 0; j < s2; j++) {
        right[j] = arr[j + mid + 1];
    }

    int i = 0, j = 0, k = l;  
    while (i < s1 && j < s2) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < s1) {
        arr[k++] = left[i++];
    }

    while (j < s2) {
        arr[k++] = right[j++];
    }
}

int* MergeSort(int arr[], int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,r);
        Merge(arr,l,r,mid);
    }
    return arr;
}

void Mergedesc(int arr[], int l,int r, int mid) {
    if (l >= r) {
        return;
    }

    int s1 = mid - l + 1; 
    int s2 = r - mid;

    int left[s1];
    int right[s2];

    for (int i = 0; i < s1; i++) {
        left[i] = arr[i + l];
    }

    for (int j = 0; j < s2; j++) {
        right[j] = arr[j + mid + 1];
    }

    int i = 0, j = 0, k = l;  
    while (i < s1 && j < s2) {
        if (left[i] > right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < s1) {
        arr[k++] = left[i++];
    }

    while (j < s2) {
        arr[k++] = right[j++];
    }
}

int* MergeSortdesc(int arr[], int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        MergeSortdesc(arr,l,mid);
        MergeSortdesc(arr,mid+1,r);
        Mergedesc(arr,l,r,mid);
    }
    return arr;
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

    int *arr=(int*)malloc(sizeof(int)*n);

    cout << "Enter elements of array:";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << "Sorted array in ascending order is:";
    MergeSort(arr, 0, n-1);
    Display(arr, n);
    cout << endl;

    cout << "Sorted array in descending order is:";
    MergeSortdesc(arr, 0, n-1);
    Display(arr, n);

    return 0;
}
