#include<math.h>
class Solution {
public:
    int Binarysearch(int n)
    {
        int l=1,r=n/2,mid,res;
        long temp;
        
        while(l<=r)
        {
            mid = l+ (r-l)/2;
            temp = (long)mid * (long)mid;
            
            if(temp==n)
                return mid;
            else if(temp<n)
                res = mid,l=mid+1;
            else
                r=mid-1;
        }
        return res;   
    }
    
    int mySqrt(int x) {
        if(x<=1)
            return x;
        
        return Binarysearch(x);
    }  
};