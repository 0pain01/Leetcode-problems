class Solution {
    public int[] prefixFunction(String s){
        int n = s.length();
        int [] pi = new int[n];
        
        for(int i = 1; i < n; i++){
            int j = pi[i-1];
            while( j>0 && s.charAt(i)!=s.charAt(j)){
                j = pi[j-1];
            }

            if(s.charAt(i) == s.charAt(j)){
                j++;
            }
            pi[i] = j;
        }

        return pi;
    }


    public int strStr(String haystack, String needle) {
         int [] lps = prefixFunction(needle);

        int pos = -1;
        int i = 0 , j = 0;

        while(i < haystack.length()){
            if(haystack.charAt(i) == needle.charAt(j)){
                j++;
                i++;
            }
            else{
                if(j != 0)
                    j = lps[j-1];
                else
                    i++;
            }
            if( j == needle.length()){
                pos = i - needle.length();
                break;
            }
        }

        return pos;
    }
}