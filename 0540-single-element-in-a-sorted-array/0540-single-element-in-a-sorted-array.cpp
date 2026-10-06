class Solution {
public:
int find(vector<int>& nums,int start,int end){
    if(start==end) return nums[start];
    int mid = start + (end-start)/2;

    if(mid%2==1) mid--;

    if(nums[mid]==nums[mid+1]) return find(nums,mid+2,end);
    else return find(nums,0,mid);

    return -1;
    
}
    int singleNonDuplicate(vector<int>& nums) {
        return find(nums,0,nums.size()-1);
    }
};