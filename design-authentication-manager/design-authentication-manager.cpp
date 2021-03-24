class AuthenticationManager {
    int ttl;
    map<string, int> m;
public:
    AuthenticationManager(int timeToLive) {
        ttl=timeToLive;
    }
    
    void generate(string tokenId, int t) {
        m.emplace(tokenId, t+ttl);
    }
    
    void renew(string tokenId, int t) {
        if(m.count(tokenId)>0)
        {
            if(m[tokenId]>t)
                m[tokenId]=t+ttl;
        }
    }
    
    int countUnexpiredTokens(int t) {
        int cnt=0;
        for(auto x:m)
        {
            if(x.second>t)
                cnt++;
        }
        return cnt;
    }
};
/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */