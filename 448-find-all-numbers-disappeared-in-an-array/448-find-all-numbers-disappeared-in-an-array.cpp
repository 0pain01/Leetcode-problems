class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        set <int> s;
        vector<int>res;
        
        for(int i=0;i<n;i++)
        {
            s.insert(nums[i]);
        }
        
        nums.clear();
        
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        
        for(int i=0;i<n;i++)
        {
            auto x = s.find(nums[i]);
            if(x==s.end())
                res.push_back(nums[i]);
            
        }
        
        return res;
        
    }
};