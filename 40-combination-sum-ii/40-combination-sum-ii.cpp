class Solution {
public:
    void helper(int idx,vector<int> cdt, set<vector<int>> &res,int target,vector<int>&temp)
    {
       
        if(target==0)
        {
            res.insert(temp);
            return;
        }
            
        
        for(int i=idx;i<cdt.size();i++)
        {
            if(i>idx && cdt[i]==cdt[i-1]) continue;
            if(cdt[i]>target) break;
            
            temp.push_back(cdt[i]);
            helper(i+1,cdt,res,target-cdt[i],temp);
            temp.pop_back();
        }
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        helper(0,candidates,res,target,temp);
        
        for(auto it=res.begin();it!=res.end();it++)
        {
            ans.push_back(*it);
        }
        return ans;  
    }
};