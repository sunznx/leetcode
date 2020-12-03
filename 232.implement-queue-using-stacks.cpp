// CreateTime: 2020-12-03 08:50:01
class MyQueue {
public:
    stack<int> stk;
    stack<int> aux;

    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stk.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        swapOut();

        auto ans = aux.top();
        aux.pop();

        swapIn();

        return ans;
    }

    /** Get the front element. */
    int peek() {
        swapOut();

        auto ans = aux.top();

        swapIn();

        return ans;
    }

    void swapOut() {
        while (stk.size()) {
            auto top = stk.top();
            stk.pop();
            aux.push(top);
        }
    }

    void swapIn() {
        while (aux.size()) {
            auto top = aux.top();
            aux.pop();
            stk.push(top);
        }
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stk.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
