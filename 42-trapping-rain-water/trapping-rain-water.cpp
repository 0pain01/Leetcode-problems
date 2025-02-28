class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
    if (n <= 2) return 0;

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int ans = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax)
                leftMax = height[left]; // Update left max
            else
                ans += leftMax - height[left]; // Water trapped

            left++;
        } else {
            if (height[right] >= rightMax)
                rightMax = height[right]; // Update right max
            else
                ans += rightMax - height[right]; // Water trapped

            right--;
        }
    }

    return ans;
    }
};