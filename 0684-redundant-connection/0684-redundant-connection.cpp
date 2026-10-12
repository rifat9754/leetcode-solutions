class Solution {
public:
    bool find_cycle(int src, int dest, vector<list<int>>& l,
                    vector<bool>& visited) {
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == dest) {
                return true;
            }
            for (int v : l[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<list<int>> l(n + 1);
       

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

             vector<bool> visited(n + 1, false);

            if (find_cycle(u, v, l, visited)) {
                return edge;
            }
            l[u].push_back(v);
            l[v].push_back(u);
        }
        return {};
    }
};