class Solution {
public:
    int bs(vector<int>&nums,int target)
    {
        int n = nums.size();
        int st=0,ed=n-1;
        if(nums[st]==target)
            return st;
        else if(nums[ed]==target)
            return ed;
        
        while(st<=ed)
        {
            int x = (st+ed)/2;
            if(nums[x]==target)
                return x;  
            else if(nums[x]<target)
                st=x+1;
            else
                ed=x-1;  
        }
        return -1;
    }
    
    vector<int>searchRange(vector<int>& nums, int target) {
   
        int n = nums.size();
        if(n==0)
            return {-1,-1};
        int mx = nums[n-1];
        
        int idx = bs(nums,target);
       
        if(idx==-1)
            return {-1,-1};
        
        int idx1=idx;
        while(idx>0 && nums[idx-1]==target)
        {
            idx--;
        }
        
        while(idx1<n-1 && nums[idx1+1]==target)
        {
            idx1++;
        }
        return {idx,idx1};
    }
};