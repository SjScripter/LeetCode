class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();

        vector<int> rev;
        int c =0;
        rev = heights;
        sort(heights.begin(),heights.end());


        for(int i = 0 ;i<n ;i++){

            if(rev[i] != heights[i]){
               c++;
                
            }

        }
            return c;
       
    }
};