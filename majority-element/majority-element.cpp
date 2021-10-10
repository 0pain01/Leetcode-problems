class Solution {
public:
    int majorityElement(vector<int>& arr) {
        
        int res=0;
        int count=1;
        
        // Moore's voting algorithm
        
        for(int i=1;i<arr.size();i++)
        {
            if(arr[res]==arr[i])
            {
                count++;
            }
            else
                count--;
            
            if(count==0)
                res=i,count=1;
        }
        
        
        return arr[res];
    }
};