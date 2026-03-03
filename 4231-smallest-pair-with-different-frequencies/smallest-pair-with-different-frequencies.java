class Solution {
    public int[] minDistinctFreqPair(int[] nums) {
        Map<Integer,Integer> mp = new TreeMap<>();

        for(int i = 0; i < nums.length;i++){
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }

        boolean first = false;
        int firstElement = 0;
        int firstFreq = 0;
        int secondElement = 0;
        int secondFreq = 0;

        boolean second = false;

        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            if(!first){
                firstElement = entry.getKey();
                firstFreq = entry.getValue();
                first = true;
            }
            else if(firstFreq != entry.getValue()){
                secondElement = entry.getKey();
                secondFreq = entry.getValue();
                break;
            }
        }
        if(secondElement == 0)
            return new int []{-1,-1};
            
        return new int[]{firstElement, secondElement};

    }
}