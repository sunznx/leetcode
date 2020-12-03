class MyStack {
public:
    queue<int> que;
    queue<int> aux;

    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        swapOut();
        que.push(x);
        swapIn();
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        auto ans = que.front();
        que.pop();
        return ans;
    }

    void swapOut() {
        while (que.size()) {
            auto front = que.front();
            que.pop();
            aux.push(front);
        }
    }

    void swapIn() {
        while (aux.size()) {
            auto front = aux.front();
            aux.pop();
            que.push(front);
        }
    }

    /** Get the top element. */
    int top() {
        return que.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que.size() == 0;
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
