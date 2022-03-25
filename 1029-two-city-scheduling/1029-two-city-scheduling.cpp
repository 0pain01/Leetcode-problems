class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        int res=0;
        vector<int>arr;
        
        for(auto it:costs)
        {
            res+=it[0];
            arr.push_back(it[1]-it[0]);
        }
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++)
        {
            res+=arr[i];
        }
        return res;
    }
};