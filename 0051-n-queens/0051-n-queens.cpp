class Solution {
public:
bool isSafe(vector<string>& board,int row,int col,int n){
    for(int j =0;j<n;j++){
        if(board[row][j]=='Q') return false;
    }
    for(int j =0;j<n;j++){
        if(board[j][col]=='Q') return false;
    }
    for(int i = row, j = col; i>=0 && j>=0; i--,j--){
        if(board[i][j]=='Q') return false;
    }
    for(int i = row, j = col; i>=0 && j<n; i--,j++){
        if(board[i][j]=='Q') return false;
    }
    return true;
}
void solve(vector<string>& board,vector<vector<string>>& ans, int n, int row){
    if(row == n){
        ans.push_back(board);
        return;
    }
    for(int i =0;i<n;i++){
        if(isSafe(board,row,i,n)){
            board[row][i] = 'Q';
            solve(board,ans,n,row+1);
            board[row][i] = '.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> ans;
        solve(board,ans,n,0);

        return ans;
    }
};