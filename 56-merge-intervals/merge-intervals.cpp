class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();
        vector<vector<int>> tt;

        sort(intervals.begin(),intervals.end());

        for(auto &interval :intervals){

            if(tt.empty() || tt.back()[1] <interval[0]){
                tt.push_back(interval);
            }
            else{
                tt.back()[1] = max(tt.back()[1],interval[1]);
            }

        }


       return tt;
        
    }
};