class Solution {
    int m,n;
    int MIN = -1000000007;

    int [][] dp = new int[501][501];  

    public int solver(int[] nums1, int [] nums2, int i, int j){
        if(n==i || m==j)
            return MIN;
        
        if(dp[i][j]!=MIN)
            return dp[i][j];
            
        int val = nums1[i]*nums2[j];
        int pickij = (nums1[i]*nums2[j]) + solver(nums1,nums2,i+1,j+1);
        int picki = solver(nums1,nums2,i,j+1);
        int pickj = solver(nums1,nums2,i+1,j);

        return dp[i][j]=Math.max(Math.max(val,pickij),Math.max(Math.max(pickij,picki),pickj)); 
    }

    public int maxDotProduct(int[] nums1, int[] nums2) {
        n = nums1.length;
        m = nums2.length;

        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                dp[i][j]=MIN;
            }
        }

        return solver(nums1,nums2,0,0);
    }
}