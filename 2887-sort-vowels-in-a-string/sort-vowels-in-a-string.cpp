class Solution {
public:
    string sortVowels(string s) {

        string vv="";
        for(char c : s){
            if(c == 'a'||c == 'e'||c == 'i'||c == 'o'||c == 'u'||c == 'A'||c == 'E'||c == 'I'||c == 'O'||c == 'U'){
                vv.push_back(c);
            }
        }

        sort(vv.begin(),vv.end());
       
        int j =0;
        for(int i =0;i<s.length();i++){
            if(s[i] == 'a'||s[i] == 'e'||s[i] == 'i'||s[i] == 'o'||s[i] == 'u'||s[i] == 'A'||s[i] == 'E'||s[i] == 'I'||s[i] == 'O'||s[i] == 'U'){
                s[i] = vv[j];
                j++;
            }
        }
        
        return s;
        
    }
};