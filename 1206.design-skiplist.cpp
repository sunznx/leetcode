// CreateTime: 2021-03-25 17:24:30

class SkiplistNode {
public:
    int val;
    vector<SkiplistNode *> next;
    SkiplistNode (int val, int sz = 32) {
        this->val = val;
        this->next.resize(sz);
    }
};


class Skiplist {
public:
    SkiplistNode *head;

    int level;

    const int MAXLEVEL = 32;
    const double P = 0.5;

    Skiplist() {
        level = 0;
        head = new SkiplistNode(INT_MIN, MAXLEVEL);
    }

    int randomLevel() {
        int level = 1;
        while (level < MAXLEVEL && ((double)(rand() & 0xFFFF) / 0XFFFF < P)) {
            level++;
        }
        return level;
    }

    vector<SkiplistNode *> findPrevs(int target) {
        vector<SkiplistNode *> prevs(MAXLEVEL, head);

        auto p = head;
        for (int i = level-1; i >= 0; i--) {
            while (p->next[i] && p->next[i]->val < target) {
                p = p->next[i];
            }
            prevs[i] = p;
        }
        return prevs;
    }

    bool search(int target) {
        auto prevs = findPrevs(target);
        auto iter = prevs[0]->next[0];
        return iter != NULL && iter->val == target;
    }

    void add(int num) {
        auto prevs = findPrevs(num);
        
        int r = randomLevel();
        level = max(level, r);

        auto node = new SkiplistNode(num, r);
        for (int k = r-1; k >= 0; k--) {
            node->next[k] = prevs[k]->next[k];
            prevs[k]->next[k] = node;
        }
    }

    bool erase(int num) {
        auto prevs = findPrevs(num);
        auto iter = prevs[0]->next[0];
        if (iter == NULL || iter->val != num) {
            return false;
        }

        for (int k = 0; k < level; k++) {
            if (prevs[k]->next[k] != iter) {
                break;
            }
            prevs[k]->next[k] = iter->next[k];
        }
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
