#include<limits.h>

class Solution {
public:
     
    int reverse(int x) {
        int num=x;
        long sum=0;
               
        if(x<INT_MIN )
            return 0;
               
        while(num!=0){     
            sum = sum * 10 + num%10;
            if(sum>INT_MAX || sum<INT_MIN)
            {return 0;break;}
                num=num/10;   
        }
       
        return sum;    
    }
};