class Solution {
public:
    int longestSubsequence(string s, int k) {
        int val = 0, cnt = 0, pow = 1;
        
        //taking the values from behind beacuse the binary works that way
        for (int i = s.size() - 1; i >= 0 && val + pow <= k; --i) 
        {
            if (s[i] == '1') 
            {
                ++cnt;
                //only counting the ones which will be present in the answer
                val += pow;
                
            }
            pow <<= 1;
            //left shifting the number 
        }
        //including all the zeroes to the answer and adding it with the number of one taken
        return count(begin(s), end(s), '0') + cnt;     
    }
};