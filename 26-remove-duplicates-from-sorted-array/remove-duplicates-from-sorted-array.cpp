class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        set<int> st;

        for(int i: nums){
            st.insert(i);
        }

        nums.clear();

        for(int x : st){
            nums.push_back(x);
        }
        return nums.size();
    }
};