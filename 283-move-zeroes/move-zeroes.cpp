class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i =0;
        int j =0;
        int c =0;
        vector<int>ans;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                c= c+1;
            }
            else{
                ans.push_back(nums[i]);
            }
        }

        while(c != 0){
            ans.push_back(0);
            c--;
        }

        nums = ans;


        
    }
};