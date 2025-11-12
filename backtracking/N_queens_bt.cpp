#include <bits/stdc++.h>
using namespace std;

// Function to print the chessboard configuration
void printSolution(vector<string> &board, int n) {
    for (int i = 0; i < n; i++) {
        cout << board[i] << "\n";
    }
    cout << "\n";
}

// Check if placing a queen at board[row][col] is safe
bool isSafe(int row, int col, vector<string> &board, int n) {
    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;

    // Check same column above
    for (int i = row - 1; i >= 0; i--)
        if (board[i][col] == 'Q') return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;

    return true;
}

// Recursive function to solve N-Queens
void solve(int row, int n, vector<string> &board) {
    // Base case: all queens placed
    if (row == n) {
        printSolution(board, n);
        return;
    }

    // Try placing queen in each column for this row
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';     // Place queen
            solve(row + 1, n, board);  // Recurse for next row // this also ensures that each queen get into each row.
            board[row][col] = '.';     // Backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<string> board(n, string(n, '.'));

    cout << "\nAll possible solutions:\n\n";
    solve(0, n, board);

    return 0;
}