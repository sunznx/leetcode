// CreateTime: 2021-03-14 10:37:42
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        typedef pair<double, int> PDI;
        priority_queue<PDI, vector<PDI>, less<PDI>> pq;

        for (int i = 0; i < classes.size(); i++) {
            double v = (double)(classes[i][0]+1)/(classes[i][1]+1) - (double)(classes[i][0])/(classes[i][1]);
            pq.push({v, i});
        }

        while (extraStudents--) {
            auto top = pq.top();
            pq.pop();

            auto i = top.second;
            classes[i][0] += 1;
            classes[i][1] += 1;
            double v = (double)(classes[i][0]+1)/(classes[i][1]+1) - (double)(classes[i][0])/(classes[i][1]);
            pq.push({v, i});
        }

        double ans = 0;
        for (int i = 0; i < classes.size(); i++) {
            ans += (double)(classes[i][0])/(classes[i][1]);
        }
        return ans/classes.size();
    }
};