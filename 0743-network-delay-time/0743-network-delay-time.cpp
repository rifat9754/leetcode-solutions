class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> g(n + 1);

        for (auto i : times) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];

            g[u].push_back({v, wt});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        pq.push({0, k});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;

            pq.pop();

            for (auto e : g[u]) {
                int v = e.first;
                int wt = e.second;

                if (dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                    pq.push({dist[v],v});
                }
            }
        }

        int ans = 0;

        for(int i = 1; i<=n; i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};