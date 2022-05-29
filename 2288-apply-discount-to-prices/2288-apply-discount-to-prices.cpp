class Solution {
public:
    string discountPrices(string sentence, int discount) {
        
        stringstream s(sentence);
        stringstream ss(sentence);
        
        string ns="";
        string word="";
        int count = 0; 
        while (ss >> word) 
            count++;
        
        int cnt=1;
        
        string word1;
        while(s>>word1)
        {
            cout<<word1<<"-";
            if(word1[0]=='$' && word1.size()>1)
            {
                int flag=0;
                for(int i=1;i<word1.size();i++)
                {
                    if(word1[i]=='$')
                        flag=1;
                    if(word1[i]>='a'&&word1[i]<='z')
                        flag=1;
                }
                
                if(flag==1)
                    {
                        if(cnt==count)
                    {
                        ns.append(word1);
                    }
                    else
                    {
                        ns.append(word1);
                        ns.append(" ");
                    }
                }
                else
                {
                    double price=0;
                    for(int i=1;i<word1.size();i++)
                    {
                        price=(price*10)+(word1[i]-'0');
                    }

                    double cost;
                    cost = price - ((price*discount)/100);

                    if(cnt==count)
                    {
                        ns.append("$");
                        stringstream t;
                        t << fixed << setprecision(2) << cost;
                        string mystring = t.str();
                        ns.append(mystring);
                    }
                    else
                    {
                        ns.append("$");
                        stringstream t;
                        t << fixed << setprecision(2) << cost;
                        string mystring = t.str();
                        ns.append(mystring);
                        ns.append(" ");
                    } 
                }
                
                
            }
            else
            {
                if(cnt==count)
                {
                    ns.append(word1);
                }
                else
                {
                    ns.append(word1);
                    ns.append(" ");
                }
            }
            cnt++;
        }
        
        return ns;
    }
};