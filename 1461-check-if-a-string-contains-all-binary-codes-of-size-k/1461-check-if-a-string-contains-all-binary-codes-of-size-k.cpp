class Solution {
public:
    bool hasAllCodes(string s, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        set<string>st;
        if(s.size()<=k)
            return false;
        
        for(int i=0;i<=s.size()-k;i++)
        {
            string t = s.substr(i,k);
            st.insert(t);
        }
        
        return st.size() == pow(2, k) ? true : false;
    }
};