#include<algorithm>
class Solution {
public:

    int maxArea(vector<int>& height) {
        int i=0,m=INT32_MIN;
        int j = height.size()-1;
        
        while(i<j)
        {
            int temp = min(height[i],height[j])*(j-i);
            m = max(temp,m);
            if(height[i]<=height[j])
                i++;
            else
                j--;
        }
       
        return m;
    }
};