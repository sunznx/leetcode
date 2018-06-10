// CreateTime: 2018-06-10 17:24:13
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
            return v < b.v;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] += 1;
        }

        priority_queue<kv> pq;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            kv item(iter->first, iter->second);
            pq.push(item);
        }

        vector<int> res;
        for (int i = 0; i < k; i++) {
            auto item = pq.top();
            cout << item.k << endl;
            res.push_back(item.k);
            pq.pop();
        }

        return res;
    }
};



