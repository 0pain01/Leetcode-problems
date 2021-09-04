class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        
        int n= queries.size();
        vector <int> res(n,0);
        
        for(int i=0;i<queries.size();i++){
            
            int h= queries[i][0]; int k = queries[i][1]; int r = queries[i][2];
            for(int j=0;j<points.size();j++){
                int x = points[j][0];
                int y = points[j][1];
                
                int temp = pow((x-h),2) + pow((y-k),2);
                
                if(temp<=(r*r)){
                    res[i]++;
                }
            }
        }
        
        return res;
  }
};