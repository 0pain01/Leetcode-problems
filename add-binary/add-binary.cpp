#include<string>
class Solution {
public:
   
    string addBinary(string a, string b) {
        
        int i=a.length()-1,j=b.length()-1;
        string res;
        int carry=0;
        while(i>=0 || j>=0){
            int sum=0;
            if(i>=0 ){
                sum+=(a[i]-'0');
                i--;
            }
             if(j>=0 ){
                sum+=(b[j]-'0');
                j--;
            }
            sum+=carry;
            res+=to_string(sum%2);
            if(sum>1){
                carry=1;
            }
            else{
                carry=0;
            }
        }
        if(carry){
            res+='1';
        }
        reverse(res.begin(),res.end());
        return res;
    }
};