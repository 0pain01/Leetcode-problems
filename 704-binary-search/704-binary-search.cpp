class Solution {
public:
    int search(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int mid;
        int i=0,j=nums.size()-1;
        
        while(i<=j)
        {
            mid=(j+i)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]<target)
            {
                i=mid+1;
            }
            if(nums[mid]>target)
            {
                j=mid-1;
            }
        }
        
        return -1;
    }
};