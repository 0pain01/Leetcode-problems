class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size();
        int idx=0;
        for(int i=0;i<n;i++){
            if(s[i]==s[idx])
            {
                continue;
            }
            if(i-idx==k){
                return true;
            }
            if(s[i]!=s[idx]){
                idx=i;
            }
        }

        if(n-idx==k)
            return true;
        return false;
    }
};