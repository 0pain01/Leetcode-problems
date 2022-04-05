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
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        
        if(n<days)
            return -1;
        
        int res=0;
        int start = *max_element(weights.begin(),weights.end());
        int end = accumulate(weights.begin(),weights.end(),0);
        
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if(isValid(weights,n,days,mid))
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