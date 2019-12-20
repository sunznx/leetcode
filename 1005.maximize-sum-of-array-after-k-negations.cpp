// CreateTime: 2019-12-21 00:40:55
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        
        priority_queue<int, vector<int>, greater<int>> q;
        
        int len = A.size();
        for (int i = 0; i < len; i++) {
            q.push(A[i]);
        }
        
        for (int i = 0; i < K; i++) {
            auto top = q.top();
            q.pop();
            
            q.push(-top);
        }
        
        int ans = 0;
        while (q.size()) {
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};
