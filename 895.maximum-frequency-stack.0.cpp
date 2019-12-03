class FreqStack {
public:
    unordered_map<int, int> m;
    unordered_map<int, stack<int>> l;
    priority_queue<int> pq;

    FreqStack() {
        
    }
    
    void push(int x) {
        int cnt = m[x] + 1;
        m[x] = cnt;
        l[cnt].push(x);
        pq.push(cnt);
    }
    
    int pop() {
        int cnt = pq.top();
        pq.pop();
        
        int x = l[cnt].top();
        l[cnt].pop();
        
        m[x] -= 1;
        
        return x;
    }
};
