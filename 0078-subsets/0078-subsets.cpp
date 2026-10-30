class Solution {
public:

vector<vector<int>> solve(vector<int>& nums, int i, vector<vector<int>>& ans,vector<int>& temp){
    if(i==nums.size()){
        ans.push_back(temp);
        return ans;
    }
    temp.push_back(nums[i]);
    solve(nums,i+1,ans,temp);

    temp.pop_back();
    solve(nums,i+1,ans,temp);
    return ans;
}

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        return solve(nums,0,ans,temp);
    }
};