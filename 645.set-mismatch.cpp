class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       int len = nums.size();
       vector<int> res (2, 0);
       vector<int> v(len+1, 0);
       
       for (int i = 1; i <= len; i++) {
           v[nums[i-1]] += 1;
       }

       for (int i = 1; i <= len; i++) {
           if (v[i] == 0) {
               res[1] = i;
           }
           if (v[i] == 2) {
               res[0] = i;
           }
       }
       
       return res;
    }
};
