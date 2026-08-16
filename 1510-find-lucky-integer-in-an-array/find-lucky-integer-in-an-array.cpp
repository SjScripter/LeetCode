class Solution {
public:
    int findLucky(vector<int>& arr) {
        map <int,int> mp;
        int m =-1;
        int ans=-1;
        for(int y : arr){
            mp[y]++;
        }

       

        for(auto g: mp){
            if(g.first == g.second){
                m = g.first;
                if(g.first >m){
                    m = g.first;
                }
                
            }
        }
        return m;
    }
};