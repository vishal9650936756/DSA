class Solution {
public:

    int binarySearch(vector<int>& nums, int beg, int end, int target) {

        if (beg > end) {
            return beg;
        }

        int mid = beg + (end - beg) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] < target) {
            return binarySearch(nums, mid + 1, end, target);
        }
        else {
            return binarySearch(nums, beg, mid - 1, target);
        }
    }

    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};