class Solution {
public:
    static bool comp(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.first==b.first)
            return a.second<b.second;
        return a.first<b.first;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>arr;
        vector<int>ans;
        for(int i=0;i<mat.size();i++)
        {
            int cnt=0;
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1)
                    cnt++;
            }
            arr.push_back(make_pair(cnt,i));
        }
        
        sort(arr.begin(),arr.end(),comp);
        int i=0;
        while(k--)
        {
            ans.push_back(arr[i].second);
            i++;
        }
        return ans;
    }
};