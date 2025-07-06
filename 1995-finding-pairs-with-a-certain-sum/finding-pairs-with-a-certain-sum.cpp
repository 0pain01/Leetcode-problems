class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int,int>mp1;
    unordered_map<int,int>mp2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;

        for(auto i:nums1)
            mp1[i]++;

        for(auto i:nums2)
            mp2[i]++;
    }
    
    void add(int index, int val) {
        mp2[nums2[index]]--;
        nums2[index]+=val;
        mp2[nums2[index]]++;
    }
    
    int count(int tot) {
        int count=0;

        for(auto i:mp1){
            if(i.second>=1){
                if(mp2[tot-i.first]>=1){
                    count+=(i.second * mp2[tot-i.first]);
                }
            }
        }

        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */