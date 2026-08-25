class Solution {
public:
    void subset(vector<int>& nums,vector<int>& ans, int i,vector<vector<int>>& all){
        if(i == nums.size()){
            all.push_back({ans});
            return;
        }
        ans.push_back(nums[i]);
        subset(nums,ans,i+1,all);
        ans.pop_back();
        subset(nums,ans,i+1,all);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> all;
        vector<int> ans;

        subset(nums,ans,0,all);
        return all;
    }
};