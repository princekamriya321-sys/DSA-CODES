#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, char num)
{
    // Check row
    for(int j = 0; j < 9; j++)
    {
        if(board[row][j] == num)
            return false;
    }

    // Check column
    for(int i = 0; i < 9; i++)
    {
        if(board[i][col] == num)
            return false;
    }

    // Check 3 x 3 box
    int sr = (row / 3) * 3;
    int sc = (col / 3) * 3;

    for(int i = sr; i < sr + 3; i++)
    {
        for(int j = sc; j < sc + 3; j++)
        {
            if(board[i][j] == num)
                return false;
        }
    }

    return true;
}

bool solve(vector<vector<char>> &board)
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] == '.')
            {
                for(char ch = '1'; ch <= '9'; ch++)
                {
                    if(isSafe(board, i, j, ch))
                    {
                        board[i][j] = ch;

                        if(solve(board))
                            return true;

                        board[i][j] = '.';
                    }
                }

                return false;
            }
        }
    }

    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}

int main()
{
    vector<vector<char>> board(9, vector<char>(9));

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    solveSudoku(board);

    cout << "Solved Sudoku:\n";

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}