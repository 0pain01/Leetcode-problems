class Solution {
    public int maxIceCream(int[] costs, int coins) {
        int arr[] = new int[100001];
    
        for(int i = 0; i < costs.length; i++)
        {
            arr[costs[i]]++;
        }
        int count = 0;
        for(int i = 1; i <= 100000; i++)
        {
            if(arr[i] > 0)
            {
                long curr = (long) (arr[i] * i);
                if(curr <= coins)
                {
                    count += arr[i];
                    coins -= curr;
                }
                else
                {
                    count += (coins/i);
                    break;
                }
            }
        }
        return count;
    }
}