class Solution {
public:

    unordered_map<char, int> m;
    priority_queue<pair<int, char>> q;

    string frequencySort(string s) {
        for (int i = 0; i < s.size(); i++) {
            Solution::m[s[i]]++;
        }


        for (int i = 0; i < s.size(); i++) {
            q.push(make_pair(m[s[i]], s[i]));
        }

        string res = "";
        while (!q.empty()) {
            res += q.top().second;
            q.pop();
        }

        return res;
    }
};
