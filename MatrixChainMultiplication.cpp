#include <iostream>
#include <climits>
using namespace std;

void printParenthesis(int i, int j, int n, int *bracket, char &name) {
    if (i == j) {
        cout << name++;
        return;
    }
    cout << "(";
    printParenthesis(i, *((bracket + i * n) + j), n, bracket, name);
    printParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, name);
    cout << ")";
}

void matrixChainOrder(int p[], int n) {
    int dp[n][n]; 
    int bracket[n][n];

    for (int i = 1; i < n; ++i)
        dp[i][i] = 0;

    for (int L = 2; L < n; ++L) {
        for (int i = 1; i < n - L + 1; ++i) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    bracket[i][j] = k;
                }
            }
        }
    }
    
    char name = 'A';

    cout << "Optimal Parenthesization: ";
    printParenthesis(1, n - 1, n, (int *)bracket, name);
    cout << endl;

    cout << "Minimum number of multiplications is " << dp[1][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    int arr[n + 1];
    cout << "Enter the dimensions of each matrix: ";
    for (int i = 0; i <= n; ++i) {
        cin >> arr[i];
    }

    matrixChainOrder(arr, n + 1);
    return 0;
}
