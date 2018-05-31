class MyStack {
public:
    queue<int> q;
    queue<int> helpq;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        if (q.size() == 0) {
            q.push(x);
        } else {
            helpq.push(x);
            while (q.size() > 0) {
                int v = q.front();
                q.pop();
                helpq.push(v);
            }

            while (helpq.size() > 0) {
                int v = helpq.front();
                helpq.pop();
                q.push(v);
            }
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int v = q.front();
        q.pop();
        return v;
    }

    /** Get the top element. */
    int top() {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.front();
 * bool param_4 = obj.empty();
 */
