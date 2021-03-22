// CreateTime: 2021-03-20 22:40:03
class AuthenticationManager {
public:
    int timeToLive;
    unordered_map<string, int> m;

    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        m[tokenId] = currentTime;
    }

    void renew(string tokenId, int currentTime) {
        if (m.find(tokenId) != m.end() && m[tokenId] + timeToLive <= currentTime) {
            m.erase(tokenId);
        }
        if (m.find(tokenId) != m.end()) {
            m[tokenId] = currentTime;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        int cnt = 0;
        for (auto &x: m) {
            if (x.second + timeToLive > currentTime) {
                cnt++;
            }
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