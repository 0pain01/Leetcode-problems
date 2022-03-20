class Solution {
public:
    void solver(vector<int>&a,vector<int>x,vector<int>y,int &ans)
    {
        int cnt=0,cntmn=0;
        
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<x.size();j++)
            {
                if(x[j]==a[i])
                {
                    cnt++;
                }
                else if(y[j]==a[i])
                {
                    cnt++;
                    cntmn++;
                }
                else
                {
                    cnt=0;
                    cntmn=0;
                }
            }
            if(cnt==x.size())
            {
                if(ans>cntmn)
                    ans=cntmn;
            }
        }
            
    }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        int n = tops.size();
 
        for(int i=0;i<n;i++)
        {
            mp1[tops[i]]++;
            mp2[bottoms[i]]++;
        }
        
        vector<int>t,b;
        int tf=INT_MIN,bf=INT_MIN;
        
        for(auto it:mp1)
        {
            if(it.second>tf)
                tf=it.second;
        }
        
        for(auto it:mp1)
        {
            if(it.second==tf)
                t.push_back(it.first);
        }
        
        for(auto it1:mp2)
        {
            if(it1.second>bf)
                bf=it1.second;
        }
        
        for(auto it1:mp2)
        {
            if(it1.second==bf)
                b.push_back(it1.first);
        }
        
        int ans =INT_MAX;
        
        solver(t,bottoms,tops,ans);

        solver(b,tops,bottoms,ans);
        
        return ans==INT_MAX?-1:ans;
        
    }
};