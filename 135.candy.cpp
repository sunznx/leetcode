// CreateTime: 2020-03-29 19:05:29
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<pair<int, int>> v;
        for (int i = 0; i < ratings.size(); i++) {
            v.push_back({ratings[i], i});
        }

        sort(v.begin(), v.end());

        int ans = 0;
        vector<int> m(v.size(), v.size());
        for (int i = 0; i < v.size(); i++) {
            auto score = v[i].first;
            auto pos = v[i].second;

            int c = 1;
            if (pos != 0 && score > ratings[pos-1]) {
                c = max(c, m[pos-1]+1);
            }
            if (pos+1 != v.size() && score > ratings[pos+1]) {
                c = max(c, m[pos+1]+1);
            }
            m[pos] = c;
            ans += c;
        }

        return ans;
    }
};