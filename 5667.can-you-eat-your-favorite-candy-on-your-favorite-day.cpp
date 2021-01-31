// CreateTime: 2021-01-31 10:51:31
class Solution {
public:
    typedef long long LL;

    vector<bool> ans;
    vector<LL> p;

    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        p.resize(candiesCount.size()+1);
        for (int i = 0; i < candiesCount.size(); i++) {
            p[i+1] = p[i] + candiesCount[i];
        }

        for (auto &query: queries) {
            auto favoriteType = query[0];
            auto favoriteDay = query[1];
            auto dailyCap = query[2];

            ans.push_back(check(candiesCount, p, favoriteType, favoriteDay, dailyCap));
        }

        return ans;
    }

    bool check(vector<int>& candiesCount, vector<LL> &p, int favoriteType, int favoriteDay, int dailyCap) {
        auto minEat = (LL)(favoriteDay+1) * 1;
        auto maxEat = (LL)(favoriteDay+1) * dailyCap;
        auto rangMin = p[favoriteType]+1;
        auto rangMax = p[favoriteType+1];

        if (maxEat < rangMin || rangMax < minEat) {
            return false;
        }
        return true;
    }
};