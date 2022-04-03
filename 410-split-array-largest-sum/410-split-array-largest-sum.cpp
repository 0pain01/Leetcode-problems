class Solution {
public:
    bool isValid(vector<int>A,int N,int M,int mid)
    {
        int sum=0;
        int cnt=1;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            if(sum>mid)
            {
                cnt++;
                sum=A[i];
            }
        }
        if(cnt>M)
            return false;
        else 
            return true;
    }
    
    int splitArray(vector<int>& nums, int m)
    {
        int n = nums.size();
        if(n<m)
            return -1;
        
        int res=-1;
        int start = *max_element(nums.begin(),nums.end());
        int end = accumulate(nums.begin(),nums.end(),0);
        
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if(isValid(nums,n,m,mid))
            {
                res=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        
        return res;
    }
};