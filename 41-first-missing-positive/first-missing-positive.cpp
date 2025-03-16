class Solution {
public:
    int MAX_N = 1e5 + 1;
    vector<int> arr;

    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        arr.assign(MAX_N, 0);  
        
        int mpe = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                mpe = min(mpe, nums[i]);
            }
        }


        for (int i = 0; i < n; i++) {
            if (nums[i] > 0 && nums[i] < MAX_N) {
                arr[nums[i] - mpe] = nums[i];
            }
        }

      
        for (int i = 0; i < MAX_N - 1; i++) {
            if (arr[i] == 0) {
                return mpe + i;
            }
        }

        return MAX_N;
    }
};
