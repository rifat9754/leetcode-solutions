class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> graph[n];

        for(int i = 0; i<flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            graph[u].push_back({v,w});
        }

        queue<pair<int, pair<int, int>>> q;
        vector<int> vec(n,INT_MAX);

        q.push({src,{0,-1}});

        while(!q.empty()){
            auto val = q.front();
            int u = val.first;
            int cost = val.second.first;
            int stop = val.second.second;

            q.pop();

            for(auto edge : graph[u]){
                int v = edge.first;
                int wt = edge.second;

                if(vec[v] > cost + wt && stop+1 <= k){
                    vec[v] = cost + wt;
                    q.push({v,{vec[v],stop+1}});
                }
            }
        }
        if(vec[dst] == INT_MAX) return -1;

        return vec[dst];
    }
};