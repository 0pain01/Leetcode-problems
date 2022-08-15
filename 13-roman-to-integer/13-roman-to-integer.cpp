#include<string>

class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        char ch[7]={'I','V','X','L','C','D','M'};
        int ind[7]={1,5,10,50,100,500,1000};
        int l=s.length();
        for(int i=0;i<l;i++){
                    if(s[i]=='I'&& s[i+1]=='V')
                    { res+=4;i=i+1; }
                    else if(s[i]=='I'&& s[i+1]=='X')
                    { res+=9; i=i+1; }
                    else if(s[i]=='X'&& s[i+1]=='L')
                    { res+=40;i=i+1; }
                    else if(s[i]=='X'&& s[i+1]=='C')
                    { res+=90; i=i+1;}
                    else if(s[i]=='C'&& s[i+1]=='D')
                    { res+=400;i=i+1; }
                    else if(s[i]=='C'&& s[i+1]=='M')
                    { res+=900;i=i+1; }
                    else{
                        for(int j=0;j<7;j++){
                            if(s[i]==ch[j]){
                                res+=ind[j];break;}
                        }
                    }
            cout<<res<< " ";
             
        }
       return res; 
    }
};