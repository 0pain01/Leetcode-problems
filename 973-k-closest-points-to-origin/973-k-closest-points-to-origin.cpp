class Solution {
public:
    static bool solver(pair<int,double>&a, pair<int ,double>&b)
    {
        return (a.second<b.second);
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int,double>>arr;
        int n = points.size();
        
        for(int i=0;i<n;i++)
        {
            double ans = sqrt((points[i][0]*points[i][0])+(points[i][1]*points[i][1]));
            arr.push_back(make_pair(i,ans));
        }
        
        sort(arr.begin(),arr.end(),solver);
       
        vector<vector<int>>ans;
        
        for(int i=0;i<k;i++)
        {
            int idx = arr[i].first;  
            ans.push_back({points[idx][0],points[idx][1]});
        }
        
        return ans;
    }
};