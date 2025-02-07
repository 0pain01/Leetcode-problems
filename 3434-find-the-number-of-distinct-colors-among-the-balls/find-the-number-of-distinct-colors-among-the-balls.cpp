class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    unordered_map<int, int> mp; 
    unordered_map<int, int> colorCount; 
    vector<int> ans;
    int distinctColors = 0;

    for (auto& query : queries) {
        int ball = query[0], color = query[1];
        if (mp.find(ball) != mp.end()) {
            int prevColor = mp[ball];
            if (--colorCount[prevColor] == 0) {
                colorCount.erase(prevColor);
                distinctColors--;
            }
        }

        mp[ball] = color;
        if (++colorCount[color] == 1) {
            distinctColors++;
        }
        ans.push_back(distinctColors);
    }
    return ans;
}
};