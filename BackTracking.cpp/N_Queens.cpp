#include <bits/stdc++.h>
bool isValid(vector<vector<int>> &board,int row, int col)
{
    //left check
    for(int i=0;i<col;++i)
    {
        if(board[row][i]==1) return false;
    }
    
    //upper left diagonal check
    for(int i=row,j=col;(i>=0 && j>=0);--i,--j)
    {
        if(board[i][j]==1) return false;
    }
    
    //bottom left corner check
    for(int i=row,j=col;(i<board.size() && j>=0);++i,--j)
    {
        if(board[i][j]==1) return false;
    }
    return true;
}

void addsolution(vector<vector<int>> &board,int n,vector<vector<int>> &ans)
{
    vector <int> state;
    for(auto i : board)
        for(auto j : i)
            state.push_back(j);
    ans.push_back(state);
}

void nQueen(vector<vector<int>> &board,int col, int n, vector<vector<int>> &ans)
{
    if(col>=n)
    {
        addsolution(board,n,ans);
        return;
    }
    for(int row=0;row<n;++row)
    {
        if(isValid(board,row,col))
        {
            board[row][col] = 1;
            nQueen(board,col+1,n,ans);
        	board[row][col]=0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> board(n,vector<int>(n,0));
    vector<vector<int>> ans;
    //function call ---> ans me store hoga mera ans
    nQueen(board,0,n,ans);
    return ans;
}
