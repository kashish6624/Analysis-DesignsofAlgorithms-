#include <iostream>
#include <string>
using namespace std;

const int Rows = 10;
const int Cols = 10;
int C[Rows][Cols];
string B[Rows][Cols];

int LCS(string X, string Y, int m, int n) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                C[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                C[i][j] = C[i - 1][j - 1] + 1;
                B[i][j] = "Diagonal";
            } else if (C[i - 1][j] >= C[i][j - 1]) {
                C[i][j] = C[i - 1][j];
                B[i][j] = "Up";
            } else {
                C[i][j] = C[i][j - 1];
                B[i][j] = "Left";
            }
        }
    }
    return C[m][n];
}

void PrintLCS(string X, int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (B[i][j] == "Diagonal") {
        PrintLCS(X, i - 1, j - 1);
        cout << X[i - 1];
    } else if (B[i][j] == "Up") {
        PrintLCS(X, i - 1, j);
    } else {
        PrintLCS(X, i, j - 1);
    }
}

int main() {
    string X, Y;
    cout << "Enter string 1:";
    cin >> X;

    cout << "Enter string 2:";
    cin >> Y;

    int m = X.length();
    int n = Y.length();

    cout << "Length of Longest Common Subsequence: " << LCS(X, Y, m, n) << endl;

    cout << "Longest Common Subsequence: ";
    PrintLCS(X, m, n);
    cout << endl;

    return 0;
}
