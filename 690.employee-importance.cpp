/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    map<int, Employee*> m;
    int res = 0;
    int getImportance(vector<Employee*> employees, int id) {
        for (int i = 0; i < employees.size(); i++) {
            int eid = employees[i]->id;
            m[eid] = employees[i];
        }
        
        dfs(id);
        return res;
    }
    
    void dfs(int id) {
        res += m[id]->importance;
        
        for (int i = 0; i < m[id]->subordinates.size(); i++) {
            dfs(m[id]->subordinates[i]);
        }
    }
};
