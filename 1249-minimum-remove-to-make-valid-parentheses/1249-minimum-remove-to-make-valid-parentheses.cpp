class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        
        int i=0,j=n-1;
        stack<char>st;
        int cnt0=0,cnt1=0;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
                cnt0++;
            if(s[i]==')')
                cnt1++;
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                st.push(s[i]);
            }
            else if(s[i]=='(' && cnt1>0 && (sum+1)>0)
            {
                st.push(s[i]);
                cnt1--;
                sum=sum+1;
            }
            else if(s[i]==')' && cnt0>0 && (sum-1)>=0)
            {
                st.push(s[i]);
                cnt0--;
                sum=sum-1;
            }
            else if(s[i]==')' && (sum-1)<0)
            {
                cnt1--;
            }
        }
        
        string res="";
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};