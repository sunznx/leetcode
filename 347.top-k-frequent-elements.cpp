class Solution {
public:

    struct kv {
        int k;
        int v;

        kv (int _k, int _v) {
            k = _k;
            v = _v;
        }

        bool operator< (const kv &b) const {
            return v > b.v;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] += 1;
        }

        priority_queue<kv> pq;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            kv item(iter->first, iter->second);
            pq.push(item);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res;
        for (int i = 0; i < k; i++) {
            auto item = pq.top();
            res.insert(res.begin(), item.k);
            pq.pop();
        }

        return res;
    }
};



