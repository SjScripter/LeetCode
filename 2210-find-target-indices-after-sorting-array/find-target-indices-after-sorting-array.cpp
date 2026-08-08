class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {

        vector<int> ex;
        vector<int> tt;
        tt = nums;
        sort(nums.begin(),nums.end());

        for(int i = 0 ;i<nums.size();i++){
            if(nums[i] == target){
                ex.push_back(i);
            }

        }
        
        if(ex.empty()){
            return {};
        }
        else{
            return ex;
        }
    }
};