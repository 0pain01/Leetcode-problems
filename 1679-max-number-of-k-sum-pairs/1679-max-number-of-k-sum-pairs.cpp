class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        int cnt =0;
        for(auto it:mp)
        {
            if(mp[k-it.first]>0)
            {
                if(k-it.first==it.first)
                {
                    cnt+=it.second/2;
                }
                else
                {
                    cnt+=min(it.second,mp[k-it.first]);
                }
                it.second=0;
                mp[k-it.first]=0;
            }
        }
        return cnt;
    }
};