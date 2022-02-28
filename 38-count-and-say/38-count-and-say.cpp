class Solution {
public:
    string countAndSay(int n) {
        string s="";
        
        for(int i=1;i<=n;i++)
        {   
            if(i==1)
                s="1";
            else if(i==2)
                s="11";
            else if(i==3)
                s="21";
            else
            {
                int j;
                int cnt=1;
                string s1="";
                for(j=0;j<s.size()-1;j++)
                {
                    if(s[j]==s[j+1])
                        cnt++;
                    else
                    {
                        s1+=(to_string(cnt)+s[j]);
                        cnt=1;
                    }
                }
                s1+=(to_string(cnt)+s[j]);
                s=s1;
            }
        }
        return s;
    }
};