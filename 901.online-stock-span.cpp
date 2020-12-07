// CreateTime: 2020-12-08 07:40:21
class StockSpanner {
public:
    typedef pair<int, int> PII;
    stack<PII> stk;

    StockSpanner() {

    }

    int next(int price) {
        int less = 0;
        while (stk.size() && price >= stk.top().first) {
            less += stk.top().second;
            stk.pop();
        }
        stk.push({price, less+1});
        return less+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
