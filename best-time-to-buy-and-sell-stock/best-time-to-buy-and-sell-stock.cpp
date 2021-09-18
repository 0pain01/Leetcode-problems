class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int j=1,max=0;
        int min=prices[0];
        
        for(int i=1;i<prices.size();i++)
        {
            if(min>=prices[i])
            {
                min=prices[i];
                
            }
            else if(min<prices[i])
            {
                if(prices[i]-min>max)
                    max=prices[i]-min;
            }
        }
        
       return max; 
    }
};