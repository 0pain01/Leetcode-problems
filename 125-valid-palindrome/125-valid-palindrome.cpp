class Solution {
public:
    bool isPalindrome(string s) {
    
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string s1;
        
        for(int i=0;i<s.size();i++)
        {
            if((s[i]>='a' && s[i]<='z')||(s[i]>='0'&&s[i]<='9'))
                s1+=s[i];
        }
        
        s=s1;
        reverse(s.begin(),s.end());
        if(s==s1)
            return true;
        else
            return false;
    }
};