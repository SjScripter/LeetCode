class Solution {
public:
    bool isSubsequence(string s, string t) {
        stack<char>st;

        for(char y : s){
            st.push(y);

        }
        if(s.length()==0){
            return true;
        }

        reverse(t.begin(),t.end());

        for(int i =0;i<t.length() && !st.empty();i++){
            if(t[i] == st.top() ){
                st.pop();
            }
        }

        if(st.empty()){
            return true;
        }        
        else{ 
            return false;
        }
    }
};