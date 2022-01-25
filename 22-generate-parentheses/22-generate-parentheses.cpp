class Solution {
public:
    
    void solver(int o,int c, vector<string>&p,string str)
    {
        if(c==0 && o==0)
        {
            p.push_back(str);
            return;
        }
        
        if(o==c)
        {
            solver(o-1,c,p,str+'(');
        }
        else
        {
            if(o!=0)
            {
                solver(o-1,c,p,str+'(');
            }
            if(o<c)
            {
                solver(o,c-1,p,str+')');
            }
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> p;
        int o=n;
        int c=n;
        string str="";
        
        solver(o,c,p,str);
        
        return p;
    }
};