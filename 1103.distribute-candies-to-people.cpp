// CreateTime: 2019-12-14 16:28:06
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people);

        int n = 1;
        int times = 0;
        while (candies) {
            int tot = (n+(n+num_people-1)) * num_people / 2;
            if (candies >= tot) {
                candies -= tot;
                times += 1;
            } else {
                for (int i = 0; i < num_people && candies; i++) {
                    int v = min(candies, n+i);
                    res[i] += v;
                    candies -= v;
                }
            }
            n = n + num_people;
        }

        if (times > 0) {
            for (int i = 0; i < num_people; i++) {
                res[i] += times * (i+1 + (i+1+(times-1) * num_people)) / 2;
            }
        }

        return res;
    }
};
