// CreateTime: 2020-11-24 20:33:36
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int len = people.size();

        sort(people.begin(), people.end());

        int l = 0;
        int r = len-1;

        int ans = 0;

        while (l <= r) {
            if (l == r) {
                l++;
                ans++;
            } else if (people[l]+people[r] <= limit) {
                l++;
                r--;
                ans++;
            } else if (people[r] <= limit) {
                r--;
                ans++;
            }
        }

        return ans;
    }
};
