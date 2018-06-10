class Solution {
public:
    struct kv {
        string k;
        int v;

        kv (string _k, int _v) {
            k = _k;
            v = _v;
        }

        bool operator< (const kv &b) const {
            if (v == b.v) {
                return k < b.k;
            }

            return v > b.v;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (int i = 0; i < words.size(); i++) {
            m[words[i]] += 1;
        }

        priority_queue<kv> pq;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            kv item(iter->first, iter->second);
            pq.push(item);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> res;
        for (int i = 0; i < k; i++) {
            auto item = pq.top();
            res.insert(res.begin(), item.k);
            pq.pop();
        }

        return res;
    }
};
