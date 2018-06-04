class MinStack {
public:
    stack<int> minStack;
    stack<int> helpStack;

    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (minStack.empty()) {
            minStack.push(x);
            helpStack.push(x);
        } else {
            helpStack.push(x);
            int minX = minStack.top();
            if (x <= minX) {
                minStack.push(x);
            }
        }
    }

    void pop() {
        int minX = minStack.top();
        int x = helpStack.top();

        if (x <= minX) {
            minStack.pop();
        }

        helpStack.pop();
    }

    int top() {
        return helpStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};
