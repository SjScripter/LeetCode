class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;

        for( int x :nums){
            mp[x]++;
        }

        for( auto u : mp){
            if(u.second > (nums.size()/2)){
                return u.first;
            }
        }
        return 0;
    }
};