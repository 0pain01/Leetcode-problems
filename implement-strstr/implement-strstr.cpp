#include<string.h>
class Solution {
public:
    int strStr(string haystack, string needle) {
        if((needle.compare(""))==0)
            return 0;
        else{
            int i,j=0;
            for(i=0;i<haystack.size();i++){
                if(haystack[i]==needle[j]){
                    j++;
                    if(j==needle.size())
                        return i-(j-1);
                }
                else{
                    i=i-j;
                    j=0;
                }
            }
            
            return -1;
        }
    }
};