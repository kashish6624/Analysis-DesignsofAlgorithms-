#include <iostream>
using namespace std;

void Display(int* arr, int n);

//Selection sort 
int* SS(int* arr, int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        if(min!=i){
            swap(arr[i],arr[min]);
        }
    }
    Display(arr,n);
    return arr;
}

//Selection sort descending using min value
int* SSdesc(int* arr, int n){
    for(int i=n-1;i>0;i--){
        int min = i;
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[min]){
                min =j;
            }
        }
        if(min!=i){
            swap(arr[i],arr[min]);
        }
    }
    Display(arr, n);
    return arr;
}

//Selection sort ascending using max value
int* maxAsc(int* arr, int n){
    for(int i=n-1;i>0;i--){
        int max = i;
        for(int j=i-1;j>=0;j--){
            if(arr[j]>arr[max]){
                max = j;
            }
        }
        if(max!=i){
            swap(arr[i],arr[max]);
        }
    }
    Display(arr, n);
    return arr;
}

//Selection sort descending using max value
int* maxSS(int* arr,int n){
    for(int i=0;i<n-1;i++){
        int max = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[max]){
                max = j;
            }
        }
        if(max!=i){
            swap(arr[i],arr[max]);
        }
    }
    Display(arr, n);
    return arr;
}

void Display(int* arr, int n){
    // cout << "Sorted array is:";
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
    
    cout << "Selection sort ascending using min value: ";
    SS(arr, n);

    cout << "Selection sort descending using min value: ";
    SSdesc(arr, n);

    cout << "Selection sort ascending using max value: ";
    maxAsc(arr,n);
    
    cout << "Selection sort descending using max value: ";
    maxSS(arr, n);

    return 0;
}