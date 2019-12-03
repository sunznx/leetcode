class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        
        while (l < r) {
            int m = (l+r) / 2;
            
            int num1 = nums[m];
            int num2 = nums[m+1];
            if (num1 > num2) {
                r = m; 
            } else if (num1 <= num2) {
                l = m+1;
            }
        }
        
        return l;
    }
};
