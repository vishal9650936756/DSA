class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = 0;
        int count = 0;
        int i = 0;
        while(i<nums.size()){
            if(count == 0){
                n = nums[i];
            }
            if(nums[i] == n){
                count++;
            }
            else{
                count--;
            }
            i++;
        }
        return n;
    }
};