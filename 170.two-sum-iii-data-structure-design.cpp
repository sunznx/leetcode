// CreateTime: 2019-12-02 10:00:16
class TwoSum {
public:
    unordered_map<long long, int> m;

    /** Initialize your data structure here. */
    TwoSum() {

    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        m[(long long)number] += 1;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto &item: m) {
            long long target = (long long)((long long)value - item.first);
            if (m.find(target) != m.end()) {
                if (target == item.first && m[target] >= 2) {
                    return true;
                } else if (target != item.first && m[target] > 0) {
                    return true;
                }
            }
        }
        return false;
    }
};