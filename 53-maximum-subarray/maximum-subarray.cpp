class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sub = nums[0];
        int curr_sub = 0;

        for(int i = 0;i < nums.size(); i++){

            curr_sub += nums[i];
            max_sub = max(max_sub, curr_sub);

            if(curr_sub < 0){
                curr_sub = 0;
            }
        }
        return(max_sub);
        
    }
};