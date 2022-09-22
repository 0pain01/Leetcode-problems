class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        string ans="";
        string word;
        while(str>>word)
        {
            reverse(word.begin(),word.end());
            ans+=word;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};