// CreateTime: 2021-01-07 08:45:42
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;

        int l = 0;
        int r = people.size()-1;
        sort(people.begin(), people.end());

        while (l <= r) {
            auto reset = limit-people[r--];
            ans++;

            if (reset >= people[l]) {
                l++;
            }
        }
        return ans;
    }
};
