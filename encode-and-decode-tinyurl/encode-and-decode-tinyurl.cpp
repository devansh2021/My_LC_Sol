class Solution {
public:
    unordered_map<int, string> m;
    int r=rand()%10000;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        while(m.find(r)!=m.end())
            r=rand()%10000;
        m.emplace(r, longUrl);
        return "http://tinyurl.com/"+to_string(r);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        shortUrl.erase(0, 19);
        return m[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));