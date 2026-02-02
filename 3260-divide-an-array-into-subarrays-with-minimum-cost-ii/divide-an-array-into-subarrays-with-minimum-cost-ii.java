class Solution {

    TreeMap<Integer, Integer> low = new TreeMap<>();
    TreeMap<Integer, Integer> high = new TreeMap<>();
    long lowSum = 0;
    int lowSize = 0;

    public long minimumCost(int[] nums, int k, int dist) {
        if (k == 1) return nums[0];

        int need = k - 1;
        int window = dist + 1;

        // initial window
        for (int i = 1; i <= window && i < nums.length; i++) {
            addLow(nums[i]);
        }
        rebalance(need);

        long ans = nums[0] + lowSum;

        for (int l = 1, r = window + 1; r < nums.length; l++, r++) {
            remove(nums[l]);
            add(nums[r]);
            rebalance(need);
            ans = Math.min(ans, nums[0] + lowSum);
        }

        return ans;
    }

    void add(int x) {
        if (low.isEmpty() || x <= low.lastKey()) addLow(x);
        else high.merge(x, 1, Integer::sum);
    }

    void addLow(int x) {
        low.merge(x, 1, Integer::sum);
        lowSum += x;
        lowSize++;
    }

    void remove(int x) {
        if (low.containsKey(x)) {
            removeLow(x);
        } else {
            removeMap(high, x);
        }
    }

    void removeLow(int x) {
        lowSum -= x;
        lowSize--;
        removeMap(low, x);
    }

    void rebalance(int need) {
        while (lowSize > need) {
            int x = low.lastKey();
            removeLow(x);
            high.merge(x, 1, Integer::sum);
        }
        while (lowSize < need) {
            int x = high.firstKey();
            removeMap(high, x);
            addLow(x);
        }
    }

    void removeMap(TreeMap<Integer, Integer> map, int x) {
        map.merge(x, -1, Integer::sum);
        if (map.get(x) == 0) map.remove(x);
    }
}
