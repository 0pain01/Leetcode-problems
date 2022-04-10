class Solution {
public:
    string minimizeResult(string expression) {
        int n = expression.size();
        int idx=0;
        
        for(int i=0;i<n;i++)
        {
            if(expression[i]=='+')
            {
                idx=i;
                break;
            }
        }
        string t1= expression.substr(0,idx);
        string t= expression.substr(idx+1,n);
        int l1=t1.size();
        int l = t.size();
        
        string res="";
        
        int min_res=INT_MAX;
        for(int i=0;i<l1;i++)
        {
            for(int j=1;j<=l;j++)
            {
                string x = expression.substr(0,i);
                string x1 = expression.substr(i,l1-i);
                string y = expression.substr(idx+1,j);
                string y1 = expression.substr(idx+j+1,l-j+1);
            
                int a=1,b=0,c=0,d=1;
                if(!x.empty())
                {
                    a=stoi(x);
                }
                if(!y1.empty())
                {
                    d=stoi(y1);
                }
                b= stoi(x1);
                c=stoi(y);
                
                int sum= b+c;
                int val = a*sum*d;
                
                if(min_res>val)
                {
                    min_res=val;
                    res= x+"("+x1+"+"+y+")"+y1;
                }
            }
        }
        
        return res;
    }
};