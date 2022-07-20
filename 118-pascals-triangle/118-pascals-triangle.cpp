class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
       vector< vector<int>> arr{{1}};
        if(numRows ==1)
            return arr;
        arr.push_back({1,1});
        
        if(numRows==2)
            return arr;
        
        else {
            int i= 1;
            while(i<numRows-1)
            {
                int side=0;
                vector<int> x;
                int n=arr[i].size();
                
                x.push_back(1);
                for(int j=0;j<n-1;j++)
                {
                    x.push_back(arr[i][j]+arr[i][j+1]);
                }
                x.push_back(1);
            
                arr.push_back(x);
                i++;
            }
            
        }

        return arr;
    }
};