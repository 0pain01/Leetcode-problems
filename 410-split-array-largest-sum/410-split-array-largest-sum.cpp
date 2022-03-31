class Solution {
public:
    bool isPossible(vector<int>&nums, int mid, int m)
{
    int sub_arr = 1;
    int sum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if(sum > mid)
        {
            sub_arr++;
            sum = nums[i];
        }
    }
    return (sub_arr <= m);
}
    
    
int splitArray(vector<int>& nums, int m)
{
    int maxi = INT_MIN, sum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        maxi = max(maxi, nums[i]);
    }
    if(m == nums.size()) return maxi;
    int ans = 0;
    int low = maxi, high = sum;
    while(low <= high)
    {
        int mid = low + (high-low) / 2;
        if(isPossible(nums, mid, m) == true)
        {
            ans = mid;
            high = mid-1;
        }
        else 
        {
            low = mid+1;
        }
    }
    return ans;
}
};