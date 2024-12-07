/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.


Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:



Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.

*/


#include<iostream>
#include<vector>
using namespace std;

//T.C = O(9^(N*N))
//S.C = O(N*N)

bool isSafe(vector<vector<char>>& board,int row, int col, char dig){
    //horizontal
    for(int j = 0; j<9; j++){
        if(board[row][j] == dig){
            return false;
        }
    }
    //vertical
    for(int i = 0; i<9;i++){
        if(board[i][col] == dig){
            return false;
        }
    }
    //grid
    int srow = (row/3)*3;
    int scol = (col/3)*3;

    for(int i = srow; i<=srow+2;i++){
        for(int j = scol; j<=scol+2;j++){
            if(board[i][j]==dig){
                return false;
            }
        }
    }
    return true;
}
bool helper(vector<vector<char>>& board,int row, int col){

    if(row==9){
        return true;
    }

    int nextRow = row, nextCol = col+1;

    if(nextCol == 9){
        nextRow = row+1;
        nextCol = 0;
    }
    if(board[row][col] != '.'){
        return helper(board,nextRow,nextCol);
    }
    for(char dig = '1'; dig<='9';dig++){
        if(isSafe(board,row,col,dig)){

            board[row][col] = dig;

            if(helper(board,nextRow,nextCol)){
                return true;
            }

            board[row][col] = '.';
        }
    }
    return false;
}
void solveSudoku(vector<vector<char>>& board) {
    helper(board,0,0);
}