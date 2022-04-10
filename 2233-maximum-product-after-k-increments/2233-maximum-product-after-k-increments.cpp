class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        for(int i=0;i<k;i++)
        {
            int k=pq.top();
            pq.pop();
            k++;
            pq.push(k);
        }
        
        long long int sum=1;
        while(!pq.empty())
        {
            sum=(sum*pq.top())%(1000000007);
            pq.pop();
        }
        return sum;
    }
};