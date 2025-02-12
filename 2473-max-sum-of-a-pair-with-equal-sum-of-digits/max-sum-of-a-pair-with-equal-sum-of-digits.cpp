class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long,long long>mp;
        long long ans =-1;

        for(int i=0;i<n;i++){
            int num =nums[i];
            long long sum=0;
            while(num){
                sum+=num%10;
                num=num/10;
            }
            if(mp.find(sum)!=mp.end()){
                ans=max(ans,(long long)nums[i]+mp[sum]);
                //mp[sum]=max(mp[sum],nums[i]);
            }
            mp[sum]=max(mp[sum],(long long)nums[i]);
        }
        return ans;


    }
};