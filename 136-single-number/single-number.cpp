class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int z=0;
        int z2=1;

        for(int i = 0;i<nums.size();i++){
            z = z^nums[i];
        }
        
        return z;
    }
};