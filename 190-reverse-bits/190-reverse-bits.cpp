

class Solution {
public:
    

    uint32_t reverseBits(uint32_t n) {
        uint32_t x = 0;
        
        int bits = 32;
        while(--bits) {
            if(n&1) 
                x |= 1;    
            n = n >> 1;          
            x = x << 1;      
        }
        if(n&1) 
            x |= 1;        
        
        return x;
    }
};