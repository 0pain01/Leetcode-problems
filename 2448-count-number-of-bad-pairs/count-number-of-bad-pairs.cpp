class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        vector<int>arr(n);

        for(int i=0;i<n;i++){
            arr[i]=nums[i]-i;
        }
        unordered_map<int,int>mp;

        long long cnt =0;
        for(int i=0;i<n;i++){
            cnt+=mp[arr[i]];
            mp[arr[i]]++;
        }
    return  (n*(n-1))/2 -cnt;
    }
};