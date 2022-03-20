class Solution {
public:
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
        
        int cnt=0,cntmn=0,ans=INT_MAX;
        
        for(int i=0;i<t.size();i++)
        {
            for(int j=0;j<n;j++)
            {
                if(tops[j]==t[i])
                {
                    cnt++;
                }
                else if(bottoms[j]==t[i])
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
            if(cnt==n)
            {
                if(ans>cntmn)
                    ans=cntmn;
            }
        }
        
        
        cnt=0;
        cntmn=0;
        
        for(int i=0;i<b.size();i++)
        {
            for(int j=0;j<n;j++)
            {
                if(bottoms[j]==b[i])
                {
                    cnt++;
                }
                else if(tops[j]==b[i])
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
            if(cnt==n)
            {
                if(ans>cntmn)
                    ans=cntmn;
            }
        }
        
        if(ans==INT_MAX)
            return -1;
        else
            return ans;
        
    }
};