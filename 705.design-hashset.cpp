// CreateTime: 2019-11-27 09:57:58
class MyHashSet {
public:
    vector<list<int>> h;
    const int MOD = 0x3fff;

    /** Initialize your data structure here. */
    MyHashSet() {
        h.resize(MOD);
    }
    
    void add(int key) {
        int mod = key % MOD;
        for (auto item: h[mod]) {
            if (item == key) {
                return;
            }
        }

        h[mod].push_back(key);
    }
    
    void remove(int key) {
        int mod = key % MOD;
        h[mod].remove(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int mod = key % MOD;
        for (auto item: h[mod]) {
            if (item == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
