class Solution {
public:
    
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long,vector<long>,greater<long>>pq;
        int n = nums.size();
        for(int i:nums){
            pq.push(i);
        }
        int cnt=0;

        while(pq.top()<k){
            long a = pq.top();
            pq.pop();
            long b = pq.top();
            pq.pop();
            long oper = (a<<1)+b;
            pq.push(oper);
            cnt++;
        }
        return cnt;
    }
};