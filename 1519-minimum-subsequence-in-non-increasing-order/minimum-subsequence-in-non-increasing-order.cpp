class Solution {
public:

    vector<int> minSubsequence(vector<int>& nums) {
        int sum =0;

        for(int i =0;i<nums.size();i++){
            sum =sum+ nums[i];

        }

        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        vector<int> arr;
        int summ =0;
        for(int j =0;j<nums.size();j++){
            summ = summ+nums[j];
            arr.push_back(nums[j]);
            if(summ >(sum - summ)){
                break;
            }

        }

        return arr;
    }
        
};