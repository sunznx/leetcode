// CreateTime: 2021-02-25 11:34:46
class LRUCache {
public:
    typedef pair<int, int> PII;

    int capacity;
    list<PII> l;
    unordered_map<int, list<PII>::iterator> m;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }

        auto iter = m[key];
        l.splice(l.begin(), l, iter);
        return iter->second;
    }

    void put(int key, int value) {
        if (m.find(key) == m.end()) {
            if (m.size() == capacity) {
                auto back = l.back();
                l.pop_back();
                m.erase(back.first);
            }
            l.push_front({key, value});
        } else {
            auto iter = m[key];
            iter->second = value;
            l.splice(l.begin(), l, iter);
        }

        m[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
