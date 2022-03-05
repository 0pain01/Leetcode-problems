class Solution {
public:
    
    int deleteAndEarn(vector<int>& nums) {
        vector<int> v(10001,0);
        for(auto &i : nums) {
            v[i] += i;
        }
        
        for(int i = 1; i < v.size(); i++) {
            v[i] = max(v[i] + (i > 1 ? v[i-2] : 0), v[i-1]); 
        }
        return v[10000];
    }
};