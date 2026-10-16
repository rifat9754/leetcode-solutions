class Solution {
public:
    class DisjointSetUnion {
    public:
        int n;
        vector<int> par, rank;

        DisjointSetUnion(int n) {
            this->n = n;
            par.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) {
                par[i] = i;
            }
        }

        void unionByRank(int a, int b) {
            int x = find(a);
            int y = find(b);

            if (x == y)
                return;

            if (rank[x] < rank[y]) {
                par[x] = y;
            } else if (rank[x] > rank[y]) {
                par[y] = x;
            } else {
                par[y] = x;
                rank[x]++;
            }
        }

        int find(int x) {
            if (par[x] == x) {
                return x;
            }
            return par[x] = find(par[x]);
        }
    };
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        DisjointSetUnion dsu(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    dsu.unionByRank(i, j);
                }
            }
        }

        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i) {
                provinces++;
            }
        }

        return provinces;
    }
};