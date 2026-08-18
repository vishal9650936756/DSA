class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j = nums.size()-1;
        int ele = -1;
        for(int i = nums.size()-2 ; i>=0 ; i--){
            if(nums[i] < nums[i+1]){
                ele = i;
                break;
            }
        }

        if(ele == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(j = nums.size() - 1; j > ele; j--) {
            if(nums[j] > nums[ele]) {
                break;
            }
        }

        swap(nums[ele],nums[j]);

        reverse(nums.begin()+ele+1,nums.end());

        return;
    }
};