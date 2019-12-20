// CreateTime: 2019-12-21 00:12:38
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int len = stones.size();
        
        priority_queue<int> q;
        for (int i = 0; i < len; i++) {
            q.push(stones[i]);
        }
        
        while (q.size() >= 2) {
            auto top1 = q.top();
            q.pop();
            
            auto top2 = q.top();
            q.pop();
            
            auto v = abs(top1 - top2);
            if (v) {
                q.push(v);
            }
        }
        
        if (q.size() == 0) {
            return 0;
        }
        
        return q.top();
    }
};
