class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n>1)
        {
           int i=0,j=1;
            while(i<n && j<n)
            {
                if(nums[i]!=0 && nums[j]!=0)
                {
                    i++;
                }
                else if(nums[i]==0 && nums[j]!=0)
                {
                    swap(nums[i],nums[j]);
                    i++;
                }
                else if(nums[i]!=0 && nums[j]==0)
                {
                    i++;
                }
                j++;
            } 
        }
        
    }
};