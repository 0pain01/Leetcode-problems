class Solution {
    int V = 26;
    long INF = (long) Integer.MAX_VALUE;
    long dist[][] = new long [V][V];
    
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dist[i][j] = (i == j) ? 0 : INF;
            }
        }


        for (int i = 0; i < original.length; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = Math.min(dist[u][v], cost[i]);
        }

        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if(dist[i][k] != INF && dist[k][j]!= INF)
                    dist[i][j] = Math.min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }

        long ans =0;

        for(int i=0;i<source.length();i++){
            int chari = source.charAt(i)-'a';
            int charj = target.charAt(i)-'a';
            if(dist[chari][charj]==INF) return -1;
            ans+=dist[chari][charj];
        }

        return ans;
    }
}