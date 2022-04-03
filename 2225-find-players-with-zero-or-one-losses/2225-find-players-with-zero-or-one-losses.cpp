class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>mp1,mp2;
        int n = matches.size();
        
        for(int i=0;i<n;i++)
        {
            mp1[matches[i][0]]++;
            mp2[matches[i][1]]++;
        }
        
        vector<vector<int>>ans;
        
        vector<int>arr1;
        for(auto it:mp1)
        {
            if(mp2.find(it.first)==mp2.end())
            {
                arr1.push_back(it.first);
            }
        }
        
        ans.push_back(arr1);
        arr1.clear();
        
        for(auto it:mp2)
        {
            if(it.second==1)
            {
                arr1.push_back(it.first);
            }
        }
        ans.push_back(arr1);
        
        return ans;
    }
};