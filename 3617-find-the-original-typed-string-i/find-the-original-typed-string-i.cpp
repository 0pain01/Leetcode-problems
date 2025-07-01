class Solution {
public:
    int possibleStringCount(string word) {
       char ch = word[0];
       int res=0;
       for(int i=1;i<word.size();i++){
            if(ch==word[i]){
                res++;
            }
            else{
                ch=word[i];
            }
       }

       return res+1;
    }
};