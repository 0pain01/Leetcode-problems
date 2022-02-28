class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int n = nums.size();
        if(n==0)
            return ans;
        int init=nums[0],end=0;
        string s="";
        int x= init;
        end=init;
        if(n==1)
        {
            s+=to_string(nums[0]);
            ans.push_back(s);
            return ans;
        }
        
        for(int i=1;i<n;i++)
        {
            if(x+1==nums[i])
            {
                end=x+1;
                x=end;
            }
            else
            {
                if(init==end)
                    s+=to_string(init);
                else
                    s+=(to_string(init) +"->" + to_string(end));
                ans.push_back(s);
                s.clear();
                init = nums[i];
                x=init;
                end=x;
            }
        }
        
        if(init==end)
        {
            ans.push_back(to_string(init));
        }
        else
        {
            s+=(to_string(init) +"->" + to_string(end));
            ans.push_back(s);
        }
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        
        return ans;
    }
};