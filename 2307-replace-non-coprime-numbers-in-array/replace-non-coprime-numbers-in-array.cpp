class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st; // use long long to avoid overflow
        for (int x : nums) {
            st.push_back(x);
            while (st.size() > 1) {
                long long a = st[st.size() - 2];
                long long b = st.back();
                long long g = gcd(a, b);
                if (g > 1) {
                    long long l = (a / g) * b; // lcm(a, b)
                    st.pop_back();
                    st.back() = l;
                } else {
                    break;
                }
            }
        }
        // Convert back to int since final values ≤ 1e8
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};
