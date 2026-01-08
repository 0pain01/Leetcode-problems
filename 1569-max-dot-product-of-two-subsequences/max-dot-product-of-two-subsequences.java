class Solution {
    int m,n;
    int MIN = -1000000007;

    //int [][] dp = new int[501][501];  

    /*
    public int solver(int[] nums1, int [] nums2, int i, int j){
        //not selecting index more than present
        if(n==i || m==j)
            return MIN;
        
        // already solved so no need to solve again
        if(dp[i][j]!=MIN)
            return dp[i][j];

        int val = nums1[i]*nums2[j];                                     // pick i and j and stop selecting
        int pickij = (nums1[i]*nums2[j]) + solver(nums1,nums2,i+1,j+1);  // pick i and j and then select more value combos
        int picki = solver(nums1,nums2,i,j+1);                           // pick i only and another j
        int pickj = solver(nums1,nums2,i+1,j);                           // pick j only and another i

        // now select max of all the 4 possibilities above
        return dp[i][j]=Math.max(Math.max(val,pickij),Math.max(Math.max(pickij,picki),pickj));   
    }
    */

    public int maxDotProduct(int[] nums1, int[] nums2) {
        n = nums1.length;
        m = nums2.length;

        int [][] dp = new int[n+1][m+2];
        //initializing the dp with lowest number for memozisation
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[i][j]=MIN;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int val = nums1[i-1]*nums2[j-1];  
                dp[i][j] = Math.max(Math.max(val,val+dp[i-1][j-1]),Math.max(Math.max(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]));
            }
        }

        return dp[n][m];
    }
}