// CreateTime: 2021-01-24 11:23:11
class Solution {
public:

    /*
      1
      1 + 2
      1 + 2 + 3
      ...
      1 + 2 + .. + k
      
      剩余部分报团取暖
      1 + 2 + .. + k = 1/2 * (k * (k + 1))
    */

    int minimumBoxes(int n) {
        int sum = 0;
        int k = 1;

        while (sum + (k*(k+1))/2 <= n) {
            sum += k*(k+1)/2;
            k++;
        }

        int bottom = (k-1)*k/2;

        int newBottom = 1;
        while (sum < n) {
            sum += newBottom;
            newBottom++;
            bottom++;
        }
        return bottom;
    }
};