class Solution {
public:

    int numTrees(int n) {
    
        vector <int> C(n+1,0);
        C[1]=1;
        C[0]=1;
        
        for(int i=2;i<=n;i++)
        {
            C[i]=0;
            for(int j=0;j<i;j++)
            {
                C[i]+=C[j]*C[i-j-1];
            }
        }
        
        return C[n];
    }
};