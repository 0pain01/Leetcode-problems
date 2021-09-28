class Solution {
public:
    bool canJump(vector<int>& nums) {
    int n = nums.size();
    int max_index = 0;
    for (int i = 0; (i < n) and (i <= max_index); i++)
    {
        max_index = max(max_index, i + nums[i]);
    }
    if ((max_index >= (n - 1)))
        return true;
    else
        return false;

    }
};