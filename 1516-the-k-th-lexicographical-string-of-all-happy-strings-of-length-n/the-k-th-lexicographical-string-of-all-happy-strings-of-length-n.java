class Solution {
    int n2;
    String dfs(String prefix, int n, int k) {
        if (n == 0)
            return prefix;
        for (char c = 'a'; c <= 'c'; c++) {
            if (prefix.trim().length() > 0 && c == prefix.charAt(prefix.length()-1))
                continue;
            int cnt = (1 << (n2 - prefix.length() - 1));
            if (cnt >= k)
                return dfs(prefix + c, n - 1, k);
            else
                k -= cnt;
        }
        return "";
    }

    String getHappyString(int n, int k) {
        n2 = n;
        return dfs("", n, k);
    }
}