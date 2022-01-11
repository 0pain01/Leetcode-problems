class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int m=INT_MIN;
        
        if(nums[0]!=0)
            return 0;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]-nums[i]!=1)
                m=nums[i]+1;
        }
        
        if(m==INT_MIN)
            m=nums[nums.size()-1]+1;
            
        return m;
    }
};