class Solution {
    public int[] minDistinctFreqPair(int[] nums) {
        TreeMap<Integer,Integer> mp = new TreeMap<>();

        for(int i = 0; i < nums.length;i++){
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }

        Map.Entry<Integer, Integer> firstEntry = mp.firstEntry();
        mp.pollFirstEntry();

        for (Map.Entry<Integer, Integer> entry : mp.entrySet()) {
            if(firstEntry.getValue() != entry.getValue()){
                return new int[]{firstEntry.getKey(), entry.getKey()};
            }
        }
        
        return new int []{-1,-1};
    }
}