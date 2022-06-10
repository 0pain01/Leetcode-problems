class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max=0,cnt=0;
        int n=s.size();
        vector <int> arr(95,0);
        if(s==""){
            return 0;
        }
        if(n==1){
            return 1;
        }
        else{
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                   if(arr[s[j]-' ']==0)
                   {
                    arr[s[j]-' ']=1;
                   }
                    else
                    {
                        for(int k=0;k<95;k++)
                        {
                            if(arr[k]==1)
                                cnt++;
                        }
                        if(max<cnt)
                            max=cnt;
                        fill(arr.begin(),arr.end(),0);
                        cnt=0;
                        break;
                    } 
                }
        
            }
        }
        return max;
    }
};