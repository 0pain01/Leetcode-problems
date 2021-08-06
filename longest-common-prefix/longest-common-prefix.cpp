#include<string>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str="";
        int k=0;
        if(strs[0]=="")
            return str;
        
        for(int i=0;i<strs[0].size();i++)
        {
            int count=0;
            char p = strs[0][k];
            for(int j=0;j<strs.size();j++)
            {
                    if(p==strs[j][k])
                    {
                        count++;
                    }
            }
            if(count==strs.size())
            {
                str=str+p;
                k++;
            }
            else
            {
                break;
            }
        }
        return str;
    }
};