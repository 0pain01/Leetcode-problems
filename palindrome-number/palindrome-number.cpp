class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        else{
            int num=x;
            long sum=0;
            
            while(num!=0){
                sum=sum*10 + num%10;
                num=num/10;
            }
            
            if(sum==x)
                return true;
            else
                return false;
        }
    }
};