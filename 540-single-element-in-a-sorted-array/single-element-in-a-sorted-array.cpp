class Solution {
public:
    int sort(vector<int>& nums, int st, int end) {

        // Only one element left
        if(st == end) {
            return nums[st];
        }

        int mid = (st + end) / 2;

        // Make sure mid is not at boundary
        if(mid == 0) {
            if(nums[mid] != nums[mid + 1])
                return nums[mid];
        }

        if(mid == nums.size() - 1) {
            if(nums[mid] != nums[mid - 1])
                return nums[mid];
        }

        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
            return nums[mid];
        }

        if(mid % 2 == 0) {
            if(nums[mid] == nums[mid+1]) {
                return sort(nums, mid+2, end);
            }
            else {
                return sort(nums, st, mid);
            }
        }
        else {
            if(nums[mid] == nums[mid-1]) {
                return sort(nums, mid+1, end);
            }
            else {
                return sort(nums, st, mid-1);
            }
        }
    }

    int singleNonDuplicate(vector<int>& nums) {
        return sort(nums, 0, nums.size() - 1);
    }
};