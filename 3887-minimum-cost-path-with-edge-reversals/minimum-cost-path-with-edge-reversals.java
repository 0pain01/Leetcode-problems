import java.util.*;

class Solution {

    static class Pair {
        int node;
        int dist;

        Pair(int node, int dist) {
            this.node = node;
            this.dist = dist;
        }
    }

    private static int dijkstra(List<List<Pair>> adj, int n) {

        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[0] = 0;

        PriorityQueue<Pair> pq =
                new PriorityQueue<>(Comparator.comparingInt(a -> a.dist));

        pq.offer(new Pair(0, 0));

        while (!pq.isEmpty()) {
            Pair curr = pq.poll();
            int u = curr.node;
            int d = curr.dist;

            // Ignore outdated entries
            if (d > dist[u]) continue;

            // Early exit when destination reached
            if (u == n - 1) return d;

            for (Pair edge : adj.get(u)) {
                int v = edge.node;
                int w = edge.dist;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.offer(new Pair(v, dist[v]));
                }
            }
        }

        return dist[n - 1] == Integer.MAX_VALUE ? -1 : dist[n - 1];
    }

    public int minCost(int n, int[][] edges) {

        List<List<Pair>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        // Build graph (NO edge deduplication)
        for (int[] e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj.get(u).add(new Pair(v, w));
            adj.get(v).add(new Pair(u, 2 * w));
        }

        return dijkstra(adj, n);
    }
}
