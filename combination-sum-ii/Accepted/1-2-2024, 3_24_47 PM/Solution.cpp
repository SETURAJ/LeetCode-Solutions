// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    
    void solve(int ind, int total, int target, vector<int>& nums, vector<int>& ds, vector<vector<int>>& res) {
        if (total == target) {
            res.push_back(ds);
            return;
        }
        for (int i = ind; i < nums.size(); ++i) {
            if (i > ind && nums[i] == nums[i - 1]) {
                continue;
            }
            if (total + nums[i] > target) {
                break; 
            }
            
            ds.push_back(nums[i]);
            solve(i + 1, total + nums[i], target, nums, ds, res);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> res;
        solve(0, 0, target, candidates, ds, res);
        return res;
    }
};
