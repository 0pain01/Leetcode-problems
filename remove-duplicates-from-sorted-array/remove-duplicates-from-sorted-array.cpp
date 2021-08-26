class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        else{
            int next=nums[0];
        int cnt=1;
        for(int i=1;i<nums.size() && cnt<=nums.size();i++){
            if(nums[i]!=next){
                next=nums[i];
                nums[cnt]=nums[i];
                cnt++;
            }
        }
       return cnt;
        }    
    }
};