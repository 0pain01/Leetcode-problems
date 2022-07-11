class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=i;
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(mp[target-nums[i]]!=i && (mp[target-nums[i]]>0 && mp[target-nums[i]]<n))
            {
                ans= {i,mp[target-nums[i]]};
                break;
            }
        }
        
        return ans;
    }
};