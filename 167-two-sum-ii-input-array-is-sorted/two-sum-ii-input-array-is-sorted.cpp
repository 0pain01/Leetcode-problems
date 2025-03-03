class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i=0,j=n-1;
        while(i<j && j<n){
            if(numbers[i]+numbers[j]==target){
                return {i+1,j+1};
            }
            if(numbers[i]+numbers[j]<target){
                i++;
            }
            else
                j--;
        }
        return {};
    }
};