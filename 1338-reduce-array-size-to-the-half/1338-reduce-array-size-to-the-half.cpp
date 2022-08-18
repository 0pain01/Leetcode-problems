class Solution {
public:
    map<int,int>mp;
    static bool solver(pair<int,int>&a,pair<int,int> &b )
    {
        return a.second>b.second;
    }
    
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int m = n;
        vector<pair<int,int>>res;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        for(auto it:mp)
        {
            res.push_back({it.first,it.second});
        }
        sort(res.begin(),res.end(),solver);
        int i=0;
        int cnt=0;
        while(m>(n/2))
        {
            m-=res[i].second;
            i++;
            cnt++;
        }
        return cnt;
    }
};