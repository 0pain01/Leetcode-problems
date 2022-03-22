class Solution {
public:
    string getSmallestString(int n, int k) {
        string str(n,'a');
        k-=n;
        
        for(int i=n-1;i>=0;i--)
        {
            int remain = min(k,25);
            str[i]+=remain;
            k-=remain;
        }
        
        return str;
    }
};