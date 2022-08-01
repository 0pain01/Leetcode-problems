class Solution {
public:
    int solver(vector<int>nums,int l,int r)
    {
        int pre=0,curr=0;
        
        for(int i=l;i<r;i++)
        {
            int temp = max(pre+ nums[i],curr);
            pre=curr;
            curr=temp;
        }
        
        return curr;
    }
        
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if(n<2) return n?nums[0]:0;
        
        return max(solver(nums,0,n-1),solver(nums,1,n));
    }
};