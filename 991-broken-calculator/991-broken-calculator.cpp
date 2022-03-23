class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(startValue == target)
            return 0;
        
        if(target<startValue)
            return startValue-target;
        
        int cnt=0;
        if(target>startValue)
        {
            long long x = startValue;
            
            while(x<target)
            {
                if(target%2)
                    target++;
                else
                    target/=2;
                cnt++;
            }
            
            cnt+=(x-target);
        }
        return cnt;
    }
};