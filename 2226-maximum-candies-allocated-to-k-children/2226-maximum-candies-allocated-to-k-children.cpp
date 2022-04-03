class Solution {
public:
    bool isValid(vector<int>nums,int n,long long k,long long mid)
    {
        long long cnt=0;
        int i=0;
        while(i<n)
        {
            cnt+=(nums[i]/mid);
            if(cnt>=k)
                return true;
            i++;
        }
            return false;
    }
    
    int maximumCandies(vector<int>& nums, long long k) {
        int n = nums.size();
       
        long long res=0;
        
        long long start = 1;
        long long end = *max_element(nums.begin(),nums.end());
        
        while(start<=end)
        {
            
            long long mid = start + (end-start)/2;
            if(isValid(nums,n,k,mid))
            {
                res=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        
        return res;
    }
};