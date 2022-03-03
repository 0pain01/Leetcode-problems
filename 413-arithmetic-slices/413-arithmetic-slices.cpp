class Solution {
public:
    int sum(int n)
    {
        int s=0;
        for(int i=n;i>=1;i--)
            s+=i;
        
        return s;
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n==1||n==2)
            return 0;
        int d1=0,d2=0;
        int cnt=0,cnt1=0;
        for(int i=1;i<n-1;i++)
        {
            d1=nums[i]-nums[i-1];
            d2=nums[i+1]-nums[i];
            
            if(d1==d2)
            {
                cnt1++;
            }
            else
            {
                cnt+=sum(cnt1);
                cnt1=0;
            }
        }
        
        cnt1=sum(cnt1);
        cnt+=cnt1;
        
        return cnt;
    }
};