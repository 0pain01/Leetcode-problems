class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();
        ans.add(new ArrayList<Integer>(Arrays.asList(1)));
        if(numRows > 1)
            ans.add(new ArrayList<Integer>(Arrays.asList(1,1)));
        
        if(numRows > 2){
            for(int cnt = 2; cnt < numRows ; cnt++){
                List<Integer> arr = new ArrayList<>();
                arr.add(1);
                for(int i = 0; i < ans.get(cnt-1).size()-1; i++){
                    arr.add(ans.get(cnt-1).get(i)+ ans.get(cnt-1).get(i+1));
                }
                arr.add(1);
                ans.add(arr);
            }
        }
        return ans;
    }
}