class Solution {
public:
    bool isSubset(int n,vector<int>&nums,int sum)
    {
        int t[n+1][sum+1];
        

        for(int i=0;i<=n;i++)
        {
            t[i][0]=1;
        }
        
        for(int i=1;i<=sum;i++)
        {
            t[0][i]=0;
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(nums[i-1]<=j)
                    t[i][j]=t[i-1][j-nums[i-1]]||t[i-1][j];
                
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[n][sum];
    }
    
    
    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        
        if(sum%2!=0)
            return false;
        else 
            return isSubset(n,nums,sum/2);
    }
};