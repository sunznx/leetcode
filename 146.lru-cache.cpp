// CreateTime: 2021-03-25 19:15:55
class LRUCache {
public:

    typedef pair<int, int> PII;
    int capacity;
    list<PII> ls;
    unordered_map<int, list<PII>::iterator> m;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }

        auto iter = m[key];
        ls.splice(ls.begin(), ls, iter);
        return iter->second;
    }

    void put(int key, int value) {
        if (m.find(key) == m.end()) {
            if (ls.size() == capacity) {
                auto back = ls.back();
                ls.pop_back();
                m.erase(back.first);
            }
            ls.push_front({key, value});
            m[key] = ls.begin();
        } else {
            auto iter = m[key];
            iter->second = value;
            ls.splice(ls.begin(), ls, iter);
            m[key] = ls.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
