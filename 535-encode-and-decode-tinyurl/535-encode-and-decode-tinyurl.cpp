class Solution {
public:
    map<string,string>mp;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        char valid[] = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        const int l =62;
        string url="http://tinyurl.com/";
        for (int i = 0; i < 6; ++i )
        {
            url+= valid[rand() % l];    
        }
        
        mp[url]=longUrl;
        return url;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));