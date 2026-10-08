class Solution {
public:
    int solve(vector<int>& nums, int n, int s2, vector<vector<int>>& DP) {
        DP[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s2; j++) {
                int take = 0;
                if (nums[i - 1] <= j) {
                    take += DP[i - 1][j - nums[i - 1]];
                }
                int nottake = DP[i - 1][j];
                DP[i][j] = take + nottake;
            }
        }
        return DP[n][s2];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();

        for (auto it : nums)
            sum += it;

        int s2 = (sum - target) / 2;

        if (abs(target) > sum)
            return 0;
        if ((sum - target) % 2 != 0)
            return 0;

        vector<vector<int>> DP(n + 1, vector<int>(s2 + 1, 0));

        return solve(nums, n, s2, DP);
    }
};