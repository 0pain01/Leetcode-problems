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
        long sumSq = 0;

        for (var entry : ls) {
            int a = entry.getValue().length;
            long f = (long) a * (a - 1) / 2; 

            f %= mod;
            sum = (sum + f) % mod;
            sumSq = (sumSq + (f * f) % mod) % mod;
        }


        long result = (sum * sum % mod - sumSq + mod) % mod;


        long inv2 = (mod + 1) / 2;
        result = (result * inv2) % mod;

        return (int) result;
    }
}