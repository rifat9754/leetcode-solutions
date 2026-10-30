class Solution {
public:
vector<vector<int>> solve(vector<int>& nums, vector<vector<int>>& ans,int i){
    if(i == nums.size()){
        ans.push_back(nums);
        return ans;
    }
    for(int j=i; j<nums.size();j++){
        swap(nums[i],nums[j]);
        solve(nums,ans,i+1);
        swap(nums[i],nums[j]);
    }
    return ans;
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        return solve(nums,ans,0);
    }
};