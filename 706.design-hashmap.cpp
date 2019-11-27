// CreateTime: 2019-11-27 09:58:01
class MyHashMap {
public:

    class kv {
    public:
        int key;
        int val;

        kv(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };

    vector<list<kv>> h;
    const int MOD = 0x3fff;

    /** Initialize your data structure here. */
    MyHashMap() {
        h.resize(MOD);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int mod = key % MOD;
        for (auto &item: h[mod]) {
            if (item.key == key) {
                item.val = value;
                return;
            }
        }
        h[mod].push_back({key, value});
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int mod = key % MOD;
        for (auto &item: h[mod]) {
            if (item.key == key) {
                return item.val;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int mod = key % MOD;
        h[mod].remove_if([key](auto item) {
                             return item.key == key;
                         });
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
