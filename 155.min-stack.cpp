// CreateTime: 2020-12-03 00:43:11
class MinStack {
public:
    stack<int> stk;             // 正常栈
    stack<int> aux;             // 最小栈

    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        if (aux.size() == 0 || x < aux.top()) {
            aux.push(x);
        } else {
            aux.push(aux.top());
        }
    }
    
    void pop() {
        stk.pop();
        aux.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return aux.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
