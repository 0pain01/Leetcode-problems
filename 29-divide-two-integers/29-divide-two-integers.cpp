class Solution {
public:
    int divide(int dividend, int divisor) {
       if(dividend==1<<31&&divisor==-1)
          return INT_MAX;
        bool sign= (dividend>0)==(divisor>0)?true:false;
        long a=abs(dividend);
        long b=abs(divisor);
        long res=0;
        while(a-b>=0){
          int count=0;
          while(a-(b<<1<<count)>=0)
          {
              count++;
          }
            res+=1<<count;
            a=a-(b<<count);
        }
        
        return sign?res:-res;
    }
};