class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
      
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });
      
        vector<int> result(n);
      
        for (int groupStart = 0; groupStart < n;) {
            int groupEnd = groupStart + 1;
            while (groupEnd < n && 
                   nums[indices[groupEnd]] - nums[indices[groupEnd - 1]] <= limit) {
                ++groupEnd;
            }
          
            vector<int> originalPositions(indices.begin() + groupStart, 
                                         indices.begin() + groupEnd);
            sort(originalPositions.begin(), originalPositions.end());
            for (int k = groupStart; k < groupEnd; ++k) {
                result[originalPositions[k - groupStart]] = nums[indices[k]];
            }
          
            groupStart = groupEnd;
        }
      
        return result;
    }
};
