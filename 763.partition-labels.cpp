// CreateTime: 2020-11-23 14:43:51
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int len = S.size();
        
        vector<int> ans;

        vector<int> need(256);
        
        for (int k = 0; k < len; k++) {
            char c = S[k];
            need[c]++;
        }
        
        vector<int> window(256);
        
        int left = 0;
        int right = 0;
        int needCount = 0;

        while (right < len) {
            char c = S[right++];
            window[c]++;
            
            if (window[c] == 1) {
                needCount++;
            }
            
            if (window[c] == need[c]) {
                needCount--;
            }
            
            if (needCount == 0) {
                ans.push_back(right-left);
                left = right;
            }
        }
        
        return ans;
    }
};
