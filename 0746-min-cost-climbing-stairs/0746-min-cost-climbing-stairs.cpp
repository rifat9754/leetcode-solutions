class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> v(n+1);
        int prv1=0;
        int prv2=0;
        int rst =prv2;
        for(int i=2;i<=n;i++){
            rst=min((prv2+cost[i-1]),(prv1+cost[i-2]));
            prv1=prv2;
            prv2=rst;
        }
        return rst;
    }
};