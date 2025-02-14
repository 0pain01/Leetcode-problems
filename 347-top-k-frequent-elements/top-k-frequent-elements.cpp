class Solution {
public:
    struct cmp {
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second; 
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }

        for(auto it:mp){
            pq.push({it.first,it.second});
        }

        vector<int>ans;

        for(int i=0;i<k;i++){
            auto x = pq.top();
            pq.pop();
            ans.push_back(x.first);
        }

        return ans;
    }
};