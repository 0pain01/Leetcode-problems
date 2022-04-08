class Solution {
public:
    void dfs(vector<vector<int>>&image,int i,int j,int newColor,int x)
    {
        if(i<0 || j<0 || i>=image.size()||j>=image[0].size()|| image[i][j]==newColor || image[i][j]!=x)
            return ;
        
        image[i][j]=newColor;
        
        dfs(image,i-1,j,newColor,x);
        dfs(image,i,j-1,newColor,x);
        dfs(image,i+1,j,newColor,x);
        dfs(image,i,j+1,newColor,x);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int x = image[sr][sc];
        dfs(image,sr,sc,newColor,x);
        return image;
    }
};