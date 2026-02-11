class KthLargest {
    private Queue<Integer> pq;
    private int k;
    public KthLargest(int k, int[] nums) {
        this.k=k;
        this.pq= new PriorityQueue<>();
        for (int num : nums) {
            add(num);
        }
    }
    
    public int add(int val) {
        pq.add(val);
        if (pq.size() > this.k) {
            pq.poll();
        }
        return pq.peek();
    }
}