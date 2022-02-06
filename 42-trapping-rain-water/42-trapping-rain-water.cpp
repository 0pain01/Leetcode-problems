class Solution {
public:
    int trap(vector<int>& height) {
        vector<int>pre;
        vector<int>suf;
        int n = height.size();
        
        pre.push_back(0);
        int max = 0;
        for(int i=1;i<n;i++)
        {
            if(max<height[i-1])
                max = height[i-1];
            
            pre.push_back(max);
        }
        
        suf.push_back(0);
        
        max=0;
        for(int i =n-2;i>=0;i--)
        {
            if(max<height[i+1])
                max = height[i+1];
            
            suf.push_back(max);
        }
        reverse (suf.begin(),suf.end());
        
        int vol=0;
        
        for(int i=0;i<n;i++)
        {
            if(min(suf[i],pre[i]) >= height[i])
            {
                vol =vol + min(suf[i],pre[i])-height[i];
            }
        }
        return vol;
    }
};