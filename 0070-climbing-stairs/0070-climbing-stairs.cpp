class Solution {
public:

int climbStairs1(vector<int>& v,int n){
            if(n==1 || n==2){
            return n;
        }
        if(v[n]!=-1) return v[n];

        return v[n]=climbStairs1(v,n-1)+climbStairs1(v,n-2);
}
    int climbStairs(int n) {
        vector<int> v(n+1,-1);

        return climbStairs1(v,n) ;
    }
};