// CreateTime: 2021-06-11 16:58:48
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph, 0);
        return ans;
    }

    void dfs(vector<vector<int>>& graph, int start) {
        if (start == graph.size()-1) {
            ans.push_back(path);
        }

        for (auto &x: graph[start]) {
            path.push_back(x);
            dfs(graph, x);
            path.pop_back();
        }
    }
};
