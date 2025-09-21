#include <iostream>
using namespace std;

int sum;

void SumOfSubsets(int s, int k, int r, int W[],int X[]){
    X[k] = 1;
    if(s+ W[k] == sum){
        cout << "Subset with sum " << sum << " found: ";
        for(int j=0;j<=k;j++){
        if (X[j] == 1) {
                cout << W[j] << " ";
            }
        }
        cout << endl;
    }
    else if(s + W[k] + W[k+1] <= sum){
        SumOfSubsets(s+W[k], k+1, r-W[k], W, X);
    }

    if(s + r - W[k] >= sum && s + W[k] <= sum){
        X[k] = 0;
        SumOfSubsets(s, k+1, r-W[k], W, X);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    int W[n];
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++) {
        cin >> W[i];
    }

    cout << "Enter the desired sum: ";
    cin >> sum;

    int X[n] = {0}; // Initialize all elements of X to 0
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += W[i];
    }

    if (totalSum < sum) {
        cout << "No subset with sum " << sum << " found!" << endl;
    }
    else {
        SumOfSubsets(0, 0, totalSum, W, X);
    }

    return 0;
}
