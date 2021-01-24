// CreateTime: 2021-01-24 11:23:11
class Solution {
public:

    /**
     * 1
     * 1 + 2
     * 1 + 2 + 3
     * ...
     * 1 + 2 + .. + k
     *
     * 剩余部分，贴着斜边放置。
     * 最底层放一个时，上一层无法放置；
     * 最底层放两个，上一次就可以再放一个；依此递推
     * 1 => 0
     * 2 => 1
     * 3 => 2 => 1
     * 4 => 3 => 2 => 1
     */

    int minimumBoxes(int n) {
        int sum = 0;
        int k = 1;

        while (sum + (k*(k+1))/2 <= n) {
            sum += k*(k+1)/2;
            k++;
        }

        int bottom = (k-1)*k/2;

        int leaves = n-sum;
        k = 1;
        while (leaves > 0) {
            leaves -= k;
            k++;
        }
        
        int newBottom = k-1;

        return bottom+newBottom;
    }
};