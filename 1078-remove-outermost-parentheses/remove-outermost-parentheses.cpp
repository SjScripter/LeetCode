class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int c=0;

        for(char ch: s){
            if(ch== '('){
                if(c>0){
                result = result +ch;
                }

                c++;
            }
            else if(ch ==')'){
                c--;
                if(c>0){
                    result += ch;
        }
            }
        }
        return result;
    }
};