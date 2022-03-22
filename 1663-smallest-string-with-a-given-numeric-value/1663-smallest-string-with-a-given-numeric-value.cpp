class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<int>arr(n,1);
        string ans="";
        int sum= accumulate(arr.begin(),arr.end(),0);
        if(sum==k)
        {
            for(int i=0;i<n;i++)
            {
                ans+='a';
            }
        }
        
        else
        {
            int i=n-1;
            while(i>=0 && sum!=k)
            {
                if(k-sum>=26)
                {
                    arr[i]=26;
                    sum+=25;
                    i--;
                }
                else
                {
                    arr[i]=k-sum+1;
                    sum+=(k-sum);
                }
            }
            
            for(int i=0;i<n;i++)
            {
                char ch ='a'+arr[i]-1;
                ans+=ch;
            }
        }
        return ans;
    }
};