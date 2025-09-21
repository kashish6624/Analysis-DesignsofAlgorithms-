#include <iostream>
#include <cmath>
using namespace std;

bool Place(int k, int i, int X[]){
    for(int j=0;j<k;j++){
        if(X[j] == i || (abs(X[j]-i) == abs(j-k))){
            return false;
        }
    }
    return true;
}

void Nqueens(int k, int n, int X[]){
    for(int i=0;i<n;i++){
        if(Place(k, i, X)){
            X[k] = i;
            if(k == n-1){ // Check if all queens are placed
                for(int j=0;j<n;j++){
                    cout << "Positions of Queen " << j+1 << "is:" << j+1 << "," << X[j]+1 << endl;
                }
                cout << endl;
            }
            else{
                Nqueens(k+1, n, X);
            }
        }
    }
}

int main(){
    int n;

    cout << "Enter number of queens to be placed:";
    cin >> n;

    int X[n];
    Nqueens(0, n, X);
    return 0;
}