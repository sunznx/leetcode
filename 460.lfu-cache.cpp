// CreateTime: 2021-07-18 23:40:48
class LFUCache {
public:
    struct Node {
        int key;
        int value;
        int idx;
        int freq;

        Node(int key, int value) {
            this->key = key;
            this->value = value;
            this->idx = 0;
            this->freq = 0;
        }

        bool operator< (const struct Node &node) const {
            return freq < node.freq || (freq == node.freq && idx < node.idx);
        }
    };

    int idx;
    int capacity;
    unordered_map<int, Node> m;
    set<Node> S;

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->idx = 0;
    }

    int get(int key) {
        if (capacity == 0) {
            return -1;
        }

        auto iter = m.find(key);
        if (iter == m.end()) {
            return -1;
        }

        auto node = iter->second;
        S.erase(node);

        node.freq++;
        node.idx = idx++;
        S.insert(node);
        iter->second = node;
        return node.value;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }

        auto iter = m.find(key);
        if (iter == m.end()) {
            if (S.size() == capacity) {
                auto begin = S.begin();
                m.erase(begin->key);
                S.erase(begin);
            }

            auto node = Node(key, value);
            node.freq++;
            node.idx = idx++;
            S.insert(node);
            m.insert({key, node});
            return;
        }

        auto node = iter->second;
        S.erase(node);

        node.freq++;
        node.idx = idx++;
        node.value = value;
        S.insert(node);
        iter->second = node;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */