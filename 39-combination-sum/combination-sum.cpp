class Solution {
public:
    void getvalue(vector<int>& candidates, int idx, int tar,
                  vector<int>& combi, vector<vector<int>>& ans) {

        if (tar == 0) {
            ans.push_back(combi);
            return;
        }

        if (idx == candidates.size() || tar < 0) {
            return;
        }

        // TAKE: use current element
        combi.push_back(candidates[idx]);

        // idx stays same because we can use the element multiple times
        getvalue(candidates, idx, tar - candidates[idx], combi, ans);

        // Backtrack
        combi.pop_back();

        // DON'T TAKE: move to next element
        getvalue(candidates, idx + 1, tar, combi, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combi;

        getvalue(candidates, 0, target, combi, ans);

        return ans;
    }
};