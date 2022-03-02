class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int n = t.size();
        int m = s.size();
        //if(s==0)
        int i=0,j=0;
        int cnt=0;
        while(i<m && j<n)
        {
            if(s[i]!=t[j])
            {
                j++;
            }
            else
            {
                i++;
                j++;
                cnt++;
            }
        }
        
        if(cnt==s.size())
            return true;
        else 
            return false;
    }
};