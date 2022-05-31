class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string>st;
        if(s.size()<=k)
            return false;
        
        for(int i=0;i<=s.size()-k;i++)
        {
            string t = s.substr(i,k);
            st.insert(t);
        }
        
        if(st.size()==pow(2,k))
            return true;
        else 
            return false;
    }
};