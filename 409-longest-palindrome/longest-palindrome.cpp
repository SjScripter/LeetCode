class Solution {
public:
    int longestPalindrome(string s) {

        map<char,int> mpp;

        for(char c : s){
            mpp[c]++;
        }
        int odd=0;
        
        for(auto &it : mpp){
            if((it.second %2) != 0){
                odd ++;
            }
        }

       if(odd<=1){
            return s.length();
       }

       return s.length()-odd+1;
    }

};