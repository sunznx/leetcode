// CreateTime: 2020-11-22 10:39:52
class Solution {
public:
    priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> minQueue; // 最小堆
    priority_queue<pair<long, long>, vector<pair<long, long>>, less<pair<long, long>>>    maxQueue; // 最大堆

    int invalidMin = 0;
    int invalidMax = 0;

    unordered_set<int> removed;
    unordered_set<int> inMaxQueue;

    pair<long, long> minQueueTop() {
        while (minQueue.size() && removed.find(minQueue.top().second) != removed.end()) {
            invalidMin--;
            minQueue.pop();
        }

        return minQueue.top();
    }

    void minQueuePush(pair<long, long> x) {
        minQueue.push(x);
        if (removed.find(x.second) != removed.end()) {
            invalidMin++;
        }
    }

    void minQueuePop() {
        auto x = minQueueTop();
        minQueue.pop();
        if (removed.find(x.second) != removed.end()) {
            invalidMin--;
        }
    }

    int minQueueSize() {
        return minQueue.size() - invalidMin;
    }

    pair<long, long> maxQueueTop() {
        while (maxQueue.size() && removed.find(maxQueue.top().second) != removed.end()) {
            invalidMax--;
            maxQueue.pop();
        }

        return maxQueue.top();
    }

    void maxQueuePush(pair<long, long> x) {
        maxQueue.push(x);
        if (removed.find(x.second) != removed.end()) {
            invalidMax++;
        }

        inMaxQueue.insert(x.second);
    }

    void maxQueuePop() {
        auto x = maxQueueTop();
        maxQueue.pop();
        if (removed.find(x.second) != removed.end()) {
            invalidMax--;
        }

        inMaxQueue.erase(x.second);
    }

    int maxQueueSize() {
        return maxQueue.size() - invalidMax;
    }

    void makeInvalid(int x) {
        removed.insert(x);
        if (inMaxQueue.find(x) != inMaxQueue.end()) {
            invalidMax++;
        } else {
            invalidMin++;
        }

        while (maxQueueSize() < minQueueSize()) {
            auto x = minQueueTop();
            minQueuePop();
            maxQueuePush(x);
        }
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;

        for (long i = 0; i < nums.size(); i++) {
            auto num = nums[i];

            if (maxQueueSize() == 0) {
                maxQueuePush({num, i});
            }

            else if (minQueueSize() == maxQueueSize()) {
                if (num > minQueueTop().first) {
                    auto x = minQueueTop();
                    minQueuePop();
                    minQueuePush({num, i});
                    maxQueuePush(x);
                } else {
                    maxQueuePush({num, i});
                }
            }

            // maxQueue.size()-invalidMax > minQueue.size()-invalidMin
            else if (num >= maxQueueTop().first) {
                minQueuePush({num, i});
            } else {
                auto x = maxQueueTop();
                maxQueuePop();
                maxQueuePush({num, i});
                minQueuePush(x);
            }

            if (i+1 >= k) {
                if (k % 2 == 0) {
                    ans.push_back((minQueueTop().first + maxQueueTop().first) / 2.0);
                } else {
                    ans.push_back(maxQueueTop().first);
                }

                makeInvalid(i + 1 - k);
            }
        }

        return ans;
    }
};