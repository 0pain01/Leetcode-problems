class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        for(int i=0;i<emails.size();i++)
        {
            int flag=0,flag1=0;
            string str="";
            
            for(int j=0;j<emails[i].size();j++)
            {
               
                if(emails[i][j]=='@')
                    str+='@',flag=1,flag1=0;
                
                else if(emails[i][j]=='.' && flag==1)
                    str+='.';
                
                else if(emails[i][j]=='+' && flag==0)
                    flag1=1;
                
                else if(emails[i][j]=='.' && flag==0)
                    continue;
                else
                {
                    if(flag1==1)
                        continue;
                    else
                        str+=emails[i][j];
                }
                                      
            }
            
            emails[i]=str;
        }
        
        for(int i=0;i<emails.size();i++)
        {
            cout<<emails[i]<<" ";
        }
        set <string> str (emails.begin(),emails.end());
        
        return str.size();
    }
};