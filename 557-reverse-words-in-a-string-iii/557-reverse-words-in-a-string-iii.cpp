class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        string word;
        int i=0;
        while(str>>word)
        {
            int n = word.size();
            reverse(s.begin()+i,s.begin()+i+n);
            i+=n;
            i++;
        }
       
        return s;
    }
};