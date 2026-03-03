class Solution {
    public int[] minDistinctFreqPair(int[] nums) {
        Map<Integer,Integer> mp = new TreeMap<>();

        for(int i = 0; i < nums.length;i++){
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }

        boolean first = false;
        int firstElement = 0;
        int firstFreq = 0;

        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            if(!first){
                firstElement = entry.getKey();
                firstFreq = entry.getValue();
                first = true;
            }
            else if(firstFreq != entry.getValue()){
                return new int[]{firstElement, entry.getKey()};
            }
        }
        
        return new int []{-1,-1};
    }
}