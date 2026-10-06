class Solution {
public:

int bs(vector<int> & nums,int low,int high){
    while(low<high){
        int mid = low + (high-low)/2;

        if(nums[mid]<nums[mid+1]){
            low = mid+1;
        }
        else {
            high = mid;
        }
    }
    return low;
}
    int peakIndexInMountainArray(vector<int>& arr) {
        int low =0;
        int high = arr.size()-1;

        return bs(arr,low,high);
    }
};

