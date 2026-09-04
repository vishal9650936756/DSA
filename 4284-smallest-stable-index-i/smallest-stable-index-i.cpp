class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int res = 0;
        int f1,f2;
        for(int i = 0;i<nums.size();i++){
            f1 = *max_element(nums.begin(),nums.begin()+i+1);
            f2 = *min_element(nums.begin()+i,nums.end());
            res = f1-f2;
            if(res <= k){
                return i;
            }
        }
        return -1;
    }
};