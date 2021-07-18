// CreateTime: 2021-07-18 23:16:00
class LRUCache {
public:
    struct KV{
        int key;
        int value;
        KV(int key, int value) {
            this->key = key;
            this->value = value;
        }
    };

    int capacity;
    list<KV> l;
    unordered_map<int, list<KV>::iterator> m;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        auto iter = m.find(key);
        if (iter == m.end()) {
            return -1;
        }

        l.splice(l.begin(), l, iter->second);
        return iter->second->value;
    }

    void put(int key, int value) {
        auto iter = m.find(key);
        if (iter == m.end()) {
            if (l.size() == capacity) {
                auto back = l.back();
                m.erase(back.key);
                l.pop_back();
            }
            l.push_front({key, value});
            m[key] = l.begin();
            return;
        }

        iter->second->value = value;
        l.splice(l.begin(), l, iter->second);
        m[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
