class Solution {
public:
    string solver(string st)
    {
        int n = st.size();
        map<char,string>ones,tens,extra;
        map<string,string>at;
        string ans="";
        ones['0']="";ones['1']="One";ones['2']="Two";ones['3']="Three";ones['4']="Four";ones['5']="Five";
        ones['6']="Six";ones['7']="Seven";ones['8']="Eight";ones['9']="Nine";
    
        at["10"]="Ten";
        at["11"]="Eleven";at["12"]="Twelve";at["13"]="Thirteen";at["14"]="Fourteen";at["15"]="Fifteen";
        at["16"]="Sixteen";at["17"]="Seventeen";at["18"]="Eighteen";at["19"]="Nineteen";
        
        tens['0']="";tens['2']="Twenty";tens['3']="Thirty";tens['4']="Forty";tens['5']="Fifty";
        tens['6']="Sixty";tens['7']="Seventy";tens['8']="Eighty";tens['9']="Ninety";
        extra['w']="Hundred";
        
        if(n==1)
        {
            ans= ones[st[0]];
        }
        if(n==2)
        {
            if(st[0]=='1')
            {
                ans= at[st];
            }
            else
            {
                ans= tens[st[0]]+" "+ones[st[1]];
            }
        }
        if(n==3)
        {
            if(st[0]=='0')
            {
                if(st[1]=='1')
                {
                    string a = st.substr(1,2);
                    ans= at[a];
                }
                else
                {
                    if(st[1]=='0')
                        ans=ones[st[2]];
                    else
                        ans= tens[st[1]]+" "+ones[st[2]];
                }
            }
            else if(st[1]=='1')
            {
                string a = st.substr(1,2);
                ans= ones[st[0]]+" "+extra['w']+" "+at[a];
            }
            else
            {
                if(st[1]=='0')
                    ans= ones[st[0]]+" Hundred "+ones[st[2]];
                else
                    ans= ones[st[0]]+" Hundred "+tens[st[1]]+" "+ones[st[2]];
            }
        }
        return ans;
    }
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        
        string st = to_string(num);
        int n = st.size();       
        
        int cnt=0;
        string ans="";
        for(int i=n-1;i>=0;i=i-3)
        {
            if(cnt==0)
            {
                if(n<3)
                    ans = solver(st);
                else
                {
                    string str = st.substr(i-2,3);
                    ans = solver(str);
                }
                cnt++;
            }
            else if(cnt==1)
            {
                string str="";
                if(i==0)
                {
                    str = st.substr(0,1);
                    str = solver(str);
                    if(st[0]=='0')
                        ans= str+" "+ans;
                    else       
                        ans= str+" "+"Thousand"+" "+ans;
                }
                else if((i-1)==0)
                {
                    str = st.substr(0,2);
                    str = solver(str);
                    if(st[i-1]=='0' && st[i-2]=='0')
                        ans= str+" "+ans;
                    else       
                        ans= str+" "+"Thousand"+" "+ans;
                }
                else
                {
                    str = st.substr(i-2,3);
                    str = solver(str);
                    if(st[i-2]=='0' && st[i-1]=='0'&&st[i]=='0')
                        ans= str+" "+ans;
                    else       
                        ans= str+" "+"Thousand"+" "+ans;
                }
                cnt++;
            }
            else if(cnt==2)
            {
                if(i==0)
                {
                    string str = st.substr(0,1);
                    str = solver(str);
                    if(st[0]=='0')
                        ans= str+" "+ans;
                    else       
                        ans= str+" "+"Million"+" "+ans;
                }
                else if((i-1)==0)
                {
                    string str = st.substr(0,2);
                    str = solver(str);
                    if(st[i-1]=='0'&& st[i-2]=='0')
                        ans= str+" "+ans;
                    else       
                        ans= str+" "+"Million"+" "+ans;
                }
                else
                {
                    string str = st.substr(i-2,3);
                    str = solver(str);
                    if(st[i-2]=='0'&& st[i-1]=='0'&&st[i]=='0')
                        ans= str+" "+ans;
                    else       
                        ans= str+" "+"Million"+" "+ans;
                }
                cnt++;
            }
            else if(cnt==3)
            {
                if(i==0)
                {
                    string str = st.substr(0,1);
                    str = solver(str);
                    ans= str+" "+"Billion"+" "+ans;
                }
                cnt++;
            }
        }
        ans = std::regex_replace(ans, std::regex("^ +| +$|( ) +"), "$1");
        return ans;
        
    }
};