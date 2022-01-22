class Solution {
public:
    
    void helper(int idx,string &s, int n , set<string> &s1)
    {
        if(idx>=n)
            return;
        
        if(s[idx]>='a'&&s[idx]<='z')
            s[idx]=s[idx]-32;
        s1.insert(s);
        helper(idx+1,s,n,s1);
        
        if(s[idx]>='A'&&s[idx]<='Z')
            s[idx]=s[idx]+32;
        s1.insert(s);
        helper(idx+1,s,n,s1);
        
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        set <string>s1;
        int n = s.length();
        
        helper(0,s,n,s1);
        
        for(auto it=s1.begin();it!=s1.end();it++)
        {
            res.push_back(*it);
        }
        
        return res;
    }
};