class Solution {
public:
    
    int solve(vector<vector<int>>& grid,int n,int m,vector<vector<bool>>& visited ){
        queue<pair<pair<int,int>,int>> que;
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    que.push({{i,j},0});
                }
            }
        }

        while(!que.empty()){
            int i = que.front().first.first;
            int j = que.front().first.second;
            int time = que.front().second;

            que.pop();

            ans = max(ans, time);

            if(i-1>=0 && !visited[i-1][j] && grid[i-1][j]== 1){
                que.push({{i-1,j},time+1});
                visited[i-1][j] = true;
            }
            if(i+1<n && !visited[i+1][j] && grid[i+1][j] == 1){
                que.push({{i+1,j},time+1});
                visited[i+1][j] = true;
            }
            if(j-1>=0 && !visited[i][j-1] && grid[i][j-1] == 1){
                que.push({{i,j-1},time+1});
                visited[i][j-1] = true;
            }
            if(j+1<m && !visited[i][j+1] && grid[i][j+1] == 1){
                que.push({{i,j+1},time+1});
                visited[i][j+1] = true;
            }                      
        }
        return ans;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        int time = solve(grid,n,m,visited);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    return -1;
                }
            }
        }

        return time;       

    }
};