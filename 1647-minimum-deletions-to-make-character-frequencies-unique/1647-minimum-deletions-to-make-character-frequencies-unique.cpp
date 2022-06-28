class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> umap;
        unordered_set<int> visited;
        
        for(auto c : s) 
            umap[c]++;
        
        int ans = 0;
        for(auto m : umap)
        {
            while(visited.count(m.second))
            {
                m.second--;
                ans++;
            }
            if(m.second) 
                visited.insert(m.second);
        }
        return ans;
        
    }
};