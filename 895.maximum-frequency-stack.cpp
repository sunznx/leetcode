// CreateTime: 2020-12-08 00:41:35
class FreqStack {
public:
    typedef pair<int, pair<int, int>> PIII;

    int idx = 0;
    unordered_map<int, int> freq;
    priority_queue<PIII, vector<PIII>, less<PIII>> pq;

    FreqStack() {

    }

    void push(int x) {
        pq.push({freq[x]++, {idx++, x}});
    }

    int pop() {
        auto top = pq.top();
        pq.pop();

        auto x = top.second.second;
        freq[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
