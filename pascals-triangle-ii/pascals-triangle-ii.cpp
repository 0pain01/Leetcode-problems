class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> arr{{1}};
        if (rowIndex==0)
            return arr[0];
        
        arr.push_back({1,1});
        if(rowIndex==1)
            return arr[1];
        
        else{
            int i=1;
            while(i<rowIndex)
            {
                vector<int> x;
                int n = arr[i].size();
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
        
        return arr[rowIndex];
    }
};