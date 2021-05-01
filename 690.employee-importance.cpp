// CreateTime: 2021-05-01 20:26:54
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int ans = 0;
    unordered_map<int, Employee*> m;

    int getImportance(vector<Employee*> employees, int id) {
        for (auto &x: employees) {
            auto id = x->id;
            m[id] = x;
        }

        dfs(id);
        return ans;
    }

    void dfs(int id) {
        ans += m[id]->importance;

        for (auto &x: m[id]->subordinates) {
            dfs(x);            
        }
    }
};
