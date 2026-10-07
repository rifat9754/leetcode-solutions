class Solution {
public:

int DP(vector<int>& nums,int sum,int n,vector<vector<int>>& dp){

    if(n==0 || sum ==0 ) return false;

    if(dp[n][sum] != -1) return dp[n][sum];

    int val = nums[n-1];
    
    if(val<=sum){
        int include = val + DP(nums,sum-val,n-1,dp);
        int exclude = DP(nums,sum,n-1,dp);
        return dp[n][sum] = max(include,exclude);
    }
    
    return dp[n][sum] = DP(nums,sum,n-1,dp);
}
    bool canPartition(vector<int>& nums) {
        int sum =0;
        int n = nums.size();

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2==1) return false;

        int target = sum/2;

        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));

        int ans = DP(nums, target, n, dp);

        return ans == target;
    }
};