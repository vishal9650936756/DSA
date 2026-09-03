class Solution {
public:

    int req_sum(int n){
        int sum = 0;
        while(n>0){
            sum = sum + n;
            n--;
        }
        return sum;
    }

    int actual_sum(vector<int>& nums, int n){
        int asum = 0;
        for(int i=0;i<n;i++){
            asum += nums[i];
        }
        int esum = req_sum(n);

        return (esum - asum);
    }

    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        return actual_sum(nums,n);
    }
};