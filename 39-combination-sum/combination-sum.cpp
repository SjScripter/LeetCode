class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        findcombo(0, target, ans, ds, candidates);
        return ans;
    }

private:
    void findcombo(int ind, int target, vector<vector<int>>& ans, vector<int>& ds, vector<int>& candidates) {
        if (ind == candidates.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if (candidates[ind] <= target) {
            ds.push_back(candidates[ind]);              
            findcombo(ind, target - candidates[ind], ans, ds, candidates);  
            ds.pop_back();                                
        }
        findcombo(ind + 1, target, ans, ds, candidates);  
    }
};