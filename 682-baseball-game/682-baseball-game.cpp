class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>s;
        int n = ops.size();
        for(int i=0;i<n;i++)
        {
            if(ops[i]=="C")
            {
                s.pop_back();
            }
            else if(ops[i]=="D")
            {
                int x = s.back();
                s.push_back(2*x);
            }
            else if(ops[i]=="+")
            {
                int n1 = s.size();
                s.push_back(s[n1-1]+s[n1-2]);
            }
            else
            {
                s.push_back(stoi(ops[i]));
            }
        }
        
        int res = accumulate(s.begin(),s.end(),0);
        return res;
    }
};