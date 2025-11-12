#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, char dig) {
    for(int i = 0; i < 6; i++) {
        if(board[row][i] == dig) return false;
    }

    for(int i = 0; i < 6; i++) {
        if(board[i][col] == dig) return false;
    }

    int srow = (row / 2) * 2;
    int scol = (col / 3) * 3;
    for(int i = srow; i < srow + 2; i++) {
        for(int j = scol; j < scol + 3; j++) {
            if(board[i][j] == dig) return false;
        }
    }

    return true;
}

bool helper(vector<vector<char>> &board, int row, int col) {
    if(row == 6) return true;

    int nextRow = row, nextCol = col + 1;
    if(nextCol == 6) {
        nextRow = row + 1;
        nextCol = 0;
    }

    if(board[row][col] != '.') {
        return helper(board, nextRow, nextCol);
    }

    for(char dig = '1'; dig <= '6'; dig++) {
        if(isSafe(board, row, col, dig)) {
            board[row][col] = dig;
            if(helper(board, nextRow, nextCol)) return true;
            board[row][col] = '.';
        }
    }

    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    helper(board, 0, 0);
}

void printBoard(const vector<vector<char>> &board) {
    cout << "\nSolved Sudoku:\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<char>> board(6, vector<char>(9));

    cout << "Enter the Sudoku board (use '.' for empty cells):\n";
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            char val;
            cin >> val;
            board[i][j] = val;
        }
    }

    solveSudoku(board);

    printBoard(board);

    return 0;
}
