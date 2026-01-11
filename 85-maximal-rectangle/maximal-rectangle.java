class Solution {
    public int []getNSR(int [] height){
        Stack<Integer> st = new Stack<>();
        int n = height.length;
        
        int [] NSR = new int[n];

        for(int i=n-1;i>=0;i--){
            if(st.isEmpty()){
                NSR[i]=n;
            }else{
                while(!st.empty() && height[st.peek()]>=height[i]){
                    st.pop();
                }

                if(st.isEmpty()){
                    NSR[i]=n;
                }
                else{
                    NSR[i]=st.peek();
                }
            }
            st.push(i);
        }
        return NSR;
    }

    public int []getNSL(int [] height){
        Stack<Integer> st = new Stack<>();
        int n = height.length;
        
        int [] NSL = new int[n];

        for(int i=0;i<n;i++){
            if(st.isEmpty()){
                NSL[i]=-1;
            }else{
                while(!st.empty() && height[st.peek()]>=height[i]){
                    st.pop();
                }

                if(st.isEmpty()){
                    NSL[i]=-1;
                }
                else{
                    NSL[i]=st.peek();
                }
            }
            st.push(i);
        }
        return NSL;
    }

    public int maxArea(int [] height){
        int size = height.length;
        int [] NSR = getNSR(height);
        int [] NSL = getNSL(height);

        int [] width = new int[size];

        
        for(int i=0;i<size;i++){
            width[i]= NSR[i]-NSL[i]-1;
        }

        int maxArea=0;
        for(int i=0;i<size;i++){
            maxArea= Math.max(maxArea,width[i]*height[i]);
        }

        return maxArea;
    }
    public int maximalRectangle(char[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

        int [] height = new int[m];

        for(int i=0;i<m;i++){
            height[i]=matrix[0][i]=='0'? 0:1;
        }

        int ans = maxArea(height);

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0'){
                    height[j]=0;
                }
                else{
                    height[j]+=1;
                }
            }

            ans = Math.max(ans,maxArea(height));
        }

        return ans;
    }
}