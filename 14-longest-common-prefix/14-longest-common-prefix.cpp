#include<string>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) 
            return "";
        
        int n=strs.size();
        string ans;
		sort(strs.begin(), strs.end());
		string a = strs[0];
		string b = strs[n-1];
		for(int i =0; i< a.size(); i++)
        {
			if(a[i] == b[i])
            {
			    ans += a[i];
		    }
		    else 
                break;
	    }
	return ans;
    }
};