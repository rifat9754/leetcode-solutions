class Solution {
public:
    const int INF = 1e9;
    int solve(vector<int>& coins, int n, int amount, vector<vector<int>>& DP) {

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {

                int nottake = DP[i - 1][j];
                int take = INF;

                if (coins[i - 1] <= j) {
                    take = 1 + DP[i][j - coins[i - 1]];
                }

                DP[i][j] = min(take, nottake);
            }
        }

        if (DP[n][amount] == INF) {
            return -1;
        }

        return DP[n][amount];
    }
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> DP(n + 1, vector<int>(amount + 1, INF));
        for (int i = 0; i <= n; i++) {
            DP[i][0] = 0;
        }

        return solve(coins, n, amount, DP);
    }
};
