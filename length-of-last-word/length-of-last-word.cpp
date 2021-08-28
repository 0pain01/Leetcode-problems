class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length(),cnt;
        std::string::reverse_iterator it;
        
        it = s.rbegin();
        
        if(n==1){
            return 1;
        }
        else{
            if(*it==' '){
            while(*it==' '){
                it++;
            }
            cnt=0;
            
            while(it!=s.rend()){
                if(*it==' ')
                    break;
                else{
                  cnt++;it++;  
                }
            }
        }
        else{
            cnt=0;
            while(it!=s.rend()){
                if(*it==' ')
                    break;
                else{
                  cnt++;it++;  
                }
            }
         }
        }
        
        return cnt;
    }
};