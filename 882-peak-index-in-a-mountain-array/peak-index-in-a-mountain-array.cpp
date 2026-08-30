class Solution {
public:
    int sort(vector<int>& nums,int st,int end){
        if(st > end){
            return -1;
        }
        int mid = (st+end)/2;
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
            return mid;
        }
        else if(nums[mid] < nums[mid-1]){
            return sort(nums,st,mid-1);
        }
        else{
            return sort(nums,mid+1,end);
        }
        
    }

    int peakIndexInMountainArray(vector<int>& arr) {
         int start = 1;
        int end = arr.size()-2;
        int res = sort(arr,start,end);
        return res;
    }
};