class Solution {
    public int maxIceCream(int[] costs, int coins) {
        int freq[] = new int[100001];
    
        for(int i = 0; i < costs.length; i++){
            freq[costs[i]]++;
        }

        int count = 0;

        for(int i = 1; i <= 100000; i++){
            if(freq[i] > 0){
                long curr = (long) (freq[i] * i);
                if(curr <= coins){
                    count += freq[i];
                    coins -= curr;
                }
                else{
                    count += (coins/i);
                    break;
                }
            }
        }
        return count;
    }
}