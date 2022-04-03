class Solution {
public:
    void calSec(int x,int &steps)
    {
        while(x!=0)
            {
                   if(x>=15)
                    {
                       steps+=(x/15);
                       x=x%15;
                        
                    }
                    else if(x>=5)
                    {
                        steps+=(x/5);
                        x=x%5;
                    }
                    else
                    {
                        steps+=(x);
                         x=0;
                    } 
            }
    }
    int convertTime(string current, string correct) {
        int h1 = (current[0]-'0')*10+(current[1]-'0');
        int s1 = (current[3]-'0')*10+(current[4]-'0');
        
        int h2 = (correct[0]-'0')*10+(correct[1]-'0');
        int s2 = (correct[3]-'0')*10+(correct[4]-'0');
        
        int carry=0;
        
        int steps=0;
        
        if(s1<s2)
        {
            int x= s2-s1;
            calSec(x,steps);
        }
        
        if(s1>s2)
        {
            int x = 60-s1+s2;
            calSec(x,steps);
        }
        
        if(h1<h2)
        {
            if(s1<=s2)
            {
                steps+=(h2-h1);
            }
            else if(s1>s2)
            {
                steps+=(h2-h1-1);
            }
        }
        
        return steps;
    }
};