class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount{{0, 1}};
      
        int result = 0;      
        int currentSum = 0; 
      
        for (int num : nums) {
            currentSum += num;
            result += prefixSumCount[currentSum - k];
          
            ++prefixSumCount[currentSum];
        }
      
        return result;
    }
};