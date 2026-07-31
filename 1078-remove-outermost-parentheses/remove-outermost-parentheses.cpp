class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string ans = "";

        for(char cc : s){
            if(cc == '('){
                if(count>0){
                ans = ans + cc;
                }
                count ++;
                
            }
            if(cc == ')'){
                count --;
                if(count > 0){
                    ans = ans+cc;
                }
            }

        }
        return ans;
    }
};