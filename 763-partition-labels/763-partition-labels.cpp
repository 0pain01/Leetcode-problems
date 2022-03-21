class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        vector<int>ans;
        int n = s.size();
        
        for(int i=0;i<n;i++)
        {
            mp[s[i]]=i;
        }
        
        int i=0;
        int maxi=INT_MIN,prev=0;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,mp[s[i]]);
            if(i==maxi)
            {
                ans.push_back(maxi-prev+1);
                prev=maxi+1;
            }
        }
        
        return ans;
    }
};