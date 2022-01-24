class Solution {
public:
    bool detectCapitalUse(string word) {
        int isupcnt=0;
        
        for(int i=0;i<word.size();i++)
        {
            if(isupper(word[i]))
                isupcnt++;
        }
        
        if(isupcnt==word.size() || isupcnt==0)
            return true;
        
        if(isupcnt==1 && isupper(word[0]))
            return true;
        
        return false;
    }
};