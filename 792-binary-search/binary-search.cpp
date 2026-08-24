class Solution {
public:
    int sort(vector<int>& nums,int target,int st,int end){
         if(st > end){
            return -1;
        }
        int mid = (st+end)/2;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[mid] > target){
            return sort(nums,target,st,mid-1);
        }
        else{
            return sort(nums,target,mid+1,end);
        }
    }

    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int res = sort(nums,target,start,end);
        return res;
    }
};