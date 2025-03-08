class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        
        int cnt=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='B')
                cnt++;
        }

        if(cnt==k)
            return 0;
        int mx =cnt;

        for(int i=k;i<n;i++){
            if(blocks[i]=='B'){
                if(blocks[i-k]=='W'){
                    cnt++;
                    mx = max(cnt,mx);
                   
                }
            }
            else{
                if(blocks[i-k]=='B'){
                    cnt--;
                }
            }
        }

        return k-mx; 
    }
};