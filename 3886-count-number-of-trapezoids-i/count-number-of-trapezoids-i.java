class Solution {
    int mod = 1000000007;
    public int countTrapezoids(int[][] points) {

        List<Map.Entry<Integer, int[][]>> ls =
        Arrays.stream(points)
                .collect(Collectors.groupingBy(
                        p -> p[1],
                        Collectors.collectingAndThen(
                                Collectors.toList(),
                                list -> list.toArray(new int[0][]))))
                .entrySet()
                .stream()
                .filter(e -> e.getValue().length >= 2)
                .toList();

        long sum = 0;
        int n = ls.size();
        long [] a = new long[n];

        for (int i = 0; i < n; i++) {
            long x = ls.get(i).getValue().length;
            a[i] = (x * (x - 1) / 2) % mod;
            sum = (sum + a[i]) % mod;
        }

        long ans = 0;

       
        for (int i = 0; i < n; i++) {
            sum = (sum - a[i] + mod) % mod;
            ans = (ans + (a[i] * sum) % mod) % mod;
        }

        return (int) ans;
    }
}