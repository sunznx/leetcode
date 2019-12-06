class MinStack {
public:
    stack<int> m;
    stack<int> s;

    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        s.push(x);
        if (m.empty() || x <= m.top()) {
            m.push(x);
        }
    }

    void pop() {
        int minX = m.top();
        int x = s.top();

        if (x <= minX) {
            m.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return m.top();
    }
};
