class Solution {
public:
    
    void check_ans(int i, int j, int n, int m, vector<vector<bool>>& visited,vector<vector<char>>& grid){

        
        
        if(i<0 || j<0 || i>=n || j>=m || visited[i][j] || grid[i][j] != '1'){
            return ;
        }

        visited[i][j] = true;


        check_ans(i-1,j,n,m,visited,grid);
        check_ans(i+1,j,n,m,visited,grid);
        check_ans(i,j-1,n,m,visited,grid);
        check_ans(i,j+1,n,m,visited,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m,false));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                        check_ans(i, j, n, m, visited, grid);
                        island++;
                }
            }
        }
        return island;
    }
};