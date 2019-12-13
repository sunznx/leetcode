// CreateTime: 2019-12-14 07:01:08
class MovingAverage {
public:
    queue<int> nums;
    int size;
    double tot;

    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        this->tot = 0;
    }
    
    double next(int val) {
        if (nums.size() == size) {
            auto top = nums.front();
            nums.pop();
            tot -= top;
        }
        
        tot += val;
        nums.push(val);
        return tot / nums.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
