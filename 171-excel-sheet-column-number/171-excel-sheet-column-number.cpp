class Solution {
public:
    string alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        
    int titleToNumber(string columnTitle) {
        
        map<int,char>mp;
        for(int i=0;i<alpha.size();i++)
            mp[alpha[i]]=i+1;
        
        int n = columnTitle.size();
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            ans=(ans*26) + mp[columnTitle[i]];
        }
        return ans;
    }
};