class Solution {
public:
    int search(vector<int>& nums2,int target)
    {
        for(int i=0;i<nums2.size();i++)
        {
            if(nums2[i]==target)
                return i;
        }
        return 0;
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        int cnt=0;
        for(int i=0;i<nums1.size();i++)
        {
            int j = search(nums2,nums1[i]);
            for(int k=j;k<nums2.size();k++)
            {
                if(nums2[k]>nums1[i])
                {
                    res.push_back(nums2[k]);
                    cnt++;
                    break;
                }
                else if(nums2[k]<=nums1[i] && k==nums2.size()-1)
                {
                    res.push_back(-1);
                }
            }
     
        }
        
        return res;
    }
};