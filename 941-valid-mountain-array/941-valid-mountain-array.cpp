class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3)
            return false;
        
        int max = INT_MIN,maxi=0,min=INT_MAX,mini=0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(max<arr[i])
            {
                max=arr[i];
                maxi=i;
            }
        }
        
        if(maxi==0 || max==arr[arr.size()-1])
            return false;

        
        for(int i=0;i<maxi;i++)
        {
            if((arr[i+1]-arr[i])<=0)
                return false;
        }
        
        for(int j=maxi;j<arr.size()-1;j++)
        {
            if((arr[j]-arr[j+1])<=0)
                return false;
        }
        
        return true;
        
    }
};