class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=0;
        for (auto i = nums.begin(); i != nums.end(); ++i) {
        if (nums[j]==val) {
            nums.erase(i);
            i--;
            j--;
        }
            j++;
    }
 
        return nums.size();
    }
};