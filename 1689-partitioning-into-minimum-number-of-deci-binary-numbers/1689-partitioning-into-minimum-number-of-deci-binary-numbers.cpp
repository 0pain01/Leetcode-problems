class Solution {
public:
    int minPartitions(string n) {
        int mx=0;
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