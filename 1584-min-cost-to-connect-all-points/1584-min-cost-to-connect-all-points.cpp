class Solution {
public:
    int mst(int x, int v, vector<vector<pair<int, int>>>& adj) {
        vector<bool> mst_set(v, false);
        int total_weight = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>pq;
        pq.push({0, x});

        while (!pq.empty()) {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if (!mst_set[u]) {
                mst_set[u] = true;
                total_weight += wt;

                for (auto it : adj[u]) {
                    int w = it.second;
                    int v = it.first;
                    if (!mst_set[v]) {
                        pq.push({w, v});
                    }
                }
            }
        }
        return total_weight;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v = points.size();
        vector<vector<pair<int, int>>> adj(v);

        for (int i = 0; i < v; i++) {
            for (int j = i + 1; j < v; j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int wt = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }
        return mst(0, v, adj);
    }
};