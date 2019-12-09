// CreateTime: 2019-12-06 11:40:23
class MaxStack {
public:
    priority_queue<pair<int, int>> que;
    stack<pair<int, int>> stk;
    unordered_set<int> s;
    int idx = 0;

    /** initialize your data structure here. */
    MaxStack() {

    }

    void push(int x) {
        que.push({x, idx});
        stk.push({x, idx});
        idx += 1;
    }

    pair<int, int> _top() {
        while (s.find(stk.top().second) != s.end()) {
            stk.pop();
        }
        return stk.top();
    }

    int pop() {
        auto top = _top();
        s.insert(top.second);
        stk.pop();
        return top.first;
    }

    int top() {
        return _top().first;
    }

    pair<int, int> _peekMax() {
        while (s.find(que.top().second) != s.end()) {
            que.pop();
        }
        return que.top();
    }

    int peekMax() {
        return _peekMax().first;
    }

    int popMax() {
        auto top = _peekMax();
        s.insert(top.second);
        que.pop();
        return top.first;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
