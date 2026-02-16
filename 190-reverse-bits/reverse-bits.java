class Solution {
    
    public int reverseBits(int n) {
        int res = 0;
        //only 32 bits integer are there
        for(int i=0; i<32; i++){
            //result left shift so that n's right side number comes to its left (in reverse order)
            //shifting rightmost digit of n every time to get it on reverse side
            res = res<<1;
            //extracting last digit (0 or 1)
            if((n&1)!=0) res += 1;
            //then removing the last digit after extracting
            n = n>>1;
        }
        return res;
    }
}