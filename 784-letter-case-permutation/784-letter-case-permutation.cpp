class Solution {
public:
    
    void helper(int idx,string &s, int n , vector<string> &res)
    {
        res.push_back(s);
        
        for(int i=idx;i<n;i++)
        {
            if(isdigit(s[i])) continue;
            
            if(isupper(s[i])) s[i]=tolower(s[i]);
            else s[i]=toupper(s[i]);
            
            helper(i+1,s,n,res);
            
            if(islower(s[i])) s[i]=toupper(s[i]);
            else s[i]=tolower(s[i]);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
       
        int n = s.length();
        
        helper(0,s,n,res);
  
        return res;
    }
};