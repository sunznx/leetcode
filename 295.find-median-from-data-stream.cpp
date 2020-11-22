// CreateTime: 2020-11-22 12:45:50
class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minQueue; // 最小堆
    priority_queue<int, vector<int>, less<int>>    maxQueue; // 最大堆

    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxQueue.size() == 0) {
            maxQueue.push(num);
            return;
        }
        
        while (minQueue.size() > maxQueue.size()) {
            auto x = minQueue.top();
            minQueue.pop();
            maxQueue.push(x);
        }

        if (maxQueue.size() == minQueue.size()) {
            if (num > minQueue.top()) {
                auto x = minQueue.top();
                minQueue.pop();
                minQueue.push(num);
                maxQueue.push(x);
                return;
            } else {
                maxQueue.push(num);
            }
            return;
        }
        
        // maxQueue.size() > minQueue.size()
        if (num >= maxQueue.top()) {
            minQueue.push(num);
            return;
        }
        
        auto x = maxQueue.top();
        maxQueue.pop();
        maxQueue.push(num);
        minQueue.push(x);
    }
    
    double findMedian() {
        if (maxQueue.size() == minQueue.size()) {
            return (maxQueue.top() + minQueue.top()) / 2.0;
        }
        return maxQueue.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
