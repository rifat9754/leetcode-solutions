class Solution {
public:
bool isPal(string s){
    string s2 = s;
    reverse(s2.begin(),s2.end());

    if(s == s2) return true;

    return false;
}
void solve(string s, vector<vector<string>>& ans,vector<string>& part ){
    if(s.size()==0){
        ans.push_back(part);
        return;
    }
    for(int i = 0;i<s.size();i++){
        string p = s.substr(0,i+1);

        if(isPal(p)){
            part.push_back(p);
            solve(s.substr(i+1),ans,part);
            part.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        solve(s,ans,part);

        return ans;
    }
};