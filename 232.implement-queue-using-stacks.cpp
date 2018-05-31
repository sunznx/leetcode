class MyQueue {
public:
    stack<int> s;
    stack<int> helps;

    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        if (s.size() == 0) {
            s.push(x);
        } else {
            while (s.size()) {
                int v = s.top();
                s.pop();
                helps.push(v);
            }
            helps.push(x);
            while (helps.size()) {
                int v = helps.top();
                helps.pop();
                s.push(v);
            }
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int v = s.top();
        s.pop();
        return v;
    }

    /** Get the front element. */
    int peek() {
        int v = s.top();
        return v;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s.size() == 0;
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
