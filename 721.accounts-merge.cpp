// CreateTime: 2018-06-09 16:41:28
class Solution {
public:
    string uf_find(map<string, string> &parent, string email) {
        while (email != parent[email]) {
            email = parent[email];
        }
        return email;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        map<string, string> parent;
        map<string, string> username_map;
        map<string, set<string>> unions;

        // init
        for (int i = 0; i < accounts.size(); i++) {
            string username = accounts[i][0];
            for (int j = 1; j < accounts[i].size(); j++) {
                parent[accounts[i][j]] = accounts[i][j];
                username_map[accounts[i][j]] = username;
            }
        }

        for (int i = 0; i < accounts.size(); i++) {
            string p1 = uf_find(parent, accounts[i][1]);
            for (int j = 2; j < accounts[i].size(); j++) {
                string p2 = uf_find(parent, accounts[i][j]);
                parent[p2] = p1;
            }
        }

        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string p = uf_find(parent, accounts[i][j]);
                unions[p].insert(accounts[i][j]);
            }
        }

        for (pair<string, set<string>> p : unions) {
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), username_map[p.first]);
            res.push_back(emails);
        }

        return res;
    }
};
