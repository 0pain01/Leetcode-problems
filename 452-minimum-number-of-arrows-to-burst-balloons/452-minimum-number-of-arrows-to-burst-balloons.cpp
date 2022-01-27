class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        
        int n= points.size();
        
        int end= points[0][1];
        int minend =end;
        int count = 1;
        
        for(int i=1;i<n;i++)
        {
            if(minend>points[i][1])
                minend=points[i][1];
            if(points[i][0]<=end && points[i][0]<=minend)
                continue;
            else
            {end=points[i][1];count++;minend=points[i][1];}
        }
        
        return count;
    }
};