class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int c=0;
        int lastsmall = INT_MIN;
        int lll = 0;

        for(int i =0;i<nums.size();i++){
            if(nums[i]-1 == lastsmall){
                c++;
                lastsmall =nums[i];
            }
            else if(lastsmall != nums[i]){
                c=1;
                lastsmall = nums[i];

            }
            lll = max(lll,c);

            }
        

        return lll;
    }
};