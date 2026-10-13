class Solution {
public:

    bool iscycle(int src, vector<bool>& visited, vector<bool>& rec, vector<vector<int>>& edges){
        visited[src] = true;
        rec[src] = true;

        for(int i = 0; i<edges.size(); i++){
            int v = edges[i][0];
            int u = edges[i][1];

            if(u == src){
                if(!visited[v]){
                    if(iscycle(v,visited,rec,edges)){
                        return true;
                    }
                }
                else if(rec[v]){
                    return true;
                }
            }
        }
        rec[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses,false);
        vector<bool> rec(numCourses,false);

        for(int i = 0; i<numCourses; i++){
            if(iscycle(i, visited, rec, prerequisites)){
                return false;
            }
        }

        return true;

    }
};