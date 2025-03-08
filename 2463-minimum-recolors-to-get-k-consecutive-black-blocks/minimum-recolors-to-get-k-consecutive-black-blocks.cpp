class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        
        int cnt=0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='B')
                cnt++;
        }

        int mx =cnt;

        for(int i=k;i<n;i++){
            if (blocks[i] == 'B') cnt++;
            if (blocks[i - k] == 'B') cnt--;
            mx = max(mx,cnt);
        }

        return k-mx; 
    }
};