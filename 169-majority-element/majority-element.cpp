class Solution {
public:
    int majorityElement(vector<int>& nums) {

        map<int,int>mp;
        for(int f : nums){
            mp[f]++;
        }
        
        for(auto u: mp){
            if(u.second > (nums.size()/2)){
                return u.first;
            }
        }
        return 0;
    }
};