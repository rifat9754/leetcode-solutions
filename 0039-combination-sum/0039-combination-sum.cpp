class Solution {
public:
void solve(vector<int>& v, int target, int idx, vector<vector<int>>& ans, vector<int>& temp){

    if(idx == v.size() || target<0){
        return;
    }
    if(target == 0 ) {
        ans.push_back(temp);
        return;
    }

    temp.push_back(v[idx]);
    solve(v,target-v[idx],idx,ans,temp);
    temp.pop_back();
    solve(v,target,idx+1,ans,temp);

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> temp;

        solve(candidates, target, 0, ans, temp);

        return ans;
    }
};