class Solution {
public:  
    int threeSumMulti(vector<int>& arr, int target) 
    {
        unordered_map<int,int>mp;

        int result = 0;

        for(int i=0;i<arr.size();++i)
        {
            result = (result + mp[target - arr[i]]) % 1000000007;

            for(int j=0;j<i;++j)
            {
                mp[arr[i] + arr[j]]++;
            }
        }
        return result;
    }
};