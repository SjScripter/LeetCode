class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int c = 0;
        vector<int> tt;

        for(int i= 0;i<nums.size();i++){

            if(nums[i] == 0){
                c++;
            }
            else{

                tt.push_back(nums[i]);

            }


        }
        while(c !=0){
            tt.push_back(0);
            c--;
        }
        nums = tt;

        
    }
};