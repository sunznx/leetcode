class FreqStack {
public:
    unordered_map<int, int> m;
    unordered_map<int, stack<int>> aux;
    int maxn = 0;

    FreqStack() {
    }

    void push(int x) {
        int v = m[x] + 1;
        m[x] = v;
        aux[v].push(x);
        maxn = max(maxn, v);
    }

    int pop() {
        int x = aux[maxn].top();
        aux[maxn].pop();
        if (aux[maxn].size() == 0) {
            maxn -= 1;
        }
        m[x] = m[x] - 1;

        return x;
    }
};
