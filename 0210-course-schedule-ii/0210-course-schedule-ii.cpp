class Solution {
public:
    bool iscycle(int src, vector<bool>& visited, vector<bool>& rec,
                 vector<vector<int>>& edges) {
        visited[src] = true;
        rec[src] = true;

        for (int i = 0; i < edges.size(); i++) {
            int v = edges[i][0];
            int u = edges[i][1];

            if (u == src) {
                if (!visited[v]) {
                    if (iscycle(v, visited, rec, edges)) {
                        rec[src] = false;
                        return true;
                    }
                } else if (rec[v]) {
                    rec[src] = false;
                    return true;
                }
            }
        }
        rec[src] = false;
        return false;
    }

    void topo_sort(int src, vector<bool>& visited, vector<vector<int>>& edges,
                   stack<int>& s) {

        visited[src] = true;

        for (int i = 0; i < edges.size(); i++) {
            int v = edges[i][0];
            int u = edges[i][1];

            if (u == src && !visited[v]) {
                if (!visited[v]) {
                    topo_sort(v, visited, edges, s);
                }
            }
        }
        s.push(src);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> rec(numCourses, false);
        vector<int> ans;
        for (int i = 0; i < numCourses; i++) {
            if (iscycle(i, visited, rec, prerequisites)) {
                return ans;
            }
        }

        stack<int> s;
        visited = vector<bool>(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                topo_sort(i, visited, prerequisites, s);
            }
        }

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};
