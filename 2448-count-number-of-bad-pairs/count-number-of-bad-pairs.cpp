class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        vector<int>arr(n);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            arr[i]=nums[i]-i;
            mp[arr[i]]++;
        }

        long long cnt =0;

        for(auto it:mp){
            if(it.second>=2){
                long long x = it.second;
                cnt +=(x*(x-1)/2);
            }
        }

        long long total_pairs = (n*(n-1))/2;
    return  total_pairs -cnt;
    }
};