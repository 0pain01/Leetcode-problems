class Solution {
public:
    int minPartitions(string n) {
        
        int mx=INT_MIN;
        for(int i=0;i<n.size();i++)
        {
            if(mx<(n[i]-'0'))
            {
                mx=n[i]-'0';
            }
        }
        
        return mx;
    }
};