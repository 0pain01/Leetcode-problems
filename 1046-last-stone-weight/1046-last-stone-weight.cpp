class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if(n==1)
            return stones[0];
        if(n==2)
        {
            if(stones[0]==stones[1])
                return 0;
            else
            {
                return abs(stones[0]-stones[1]);
            }
        }
        
        int i=n-2;
        
        while(i>=0)
        {
            sort(stones.begin(),stones.end());
            int x = stones[i];
            int y = stones[i+1];
            stones.pop_back();
            stones.pop_back();
 
            if(x==y)
            {
                i=i-2;
            }
            else
            {
                stones.push_back(y-x); 
                n=n+1;
                i--;
            }
            
            
        }
        if (stones.size()==0)
            return 0;
        else
            return stones[0];
    }
    
  
    
};