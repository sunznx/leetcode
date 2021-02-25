// CreateTime: 2021-02-24 23:47:01
class LFUCache {
    typedef tuple<int, int, int> PII;

    int minfreq;
    int capacity;
    unordered_map<int, list<PII>::iterator> m;
    unordered_map<int, list<PII>> freq;

public:
    LFUCache(int capacity) {
        this->minfreq = INT_MAX;
        this->capacity = capacity;
    }

    int get(int key) {
        if (capacity == 0) {
            return -1;
        }

        if (m.find(key) == m.end()) {
            return -1;
        }

        auto iter = m[key];
        auto [k, v, f] = *iter;

        freq[f].erase(iter);
        freq[f+1].push_front({k, v, f+1});
        m[key] = freq[f+1].begin();

        if (f == minfreq && freq[f].size() == 0) {
            minfreq = f+1;
        }

        return v;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }

        if (m.find(key) == m.end()) {
            if (m.size() == capacity) {
                auto [k, v, f] = freq[minfreq].back();
                freq[minfreq].pop_back();
                m.erase(k);
            }

            freq[1].push_front({key, value, 1});
            minfreq = 1;
            m[key] = freq[1].begin();
        } else {
            auto iter = m[key];
            auto [k, v, f] = *iter;
            freq[f].erase(iter);
            freq[f+1].push_front({key, value, f+1});
            if (f == minfreq && freq[f].size() == 0) {
                minfreq = f+1;
            }
            m[key] = freq[f+1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */