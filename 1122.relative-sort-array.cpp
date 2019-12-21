// CreateTime: 2019-12-21 01:26:09
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int len1 = arr1.size();
        int len2 = arr2.size();
        
        unordered_map<int, int> m;
        for (int i = 0; i < len2; i++) {
            m[arr2[i]] = i;
        }

        int idx = len1;
        int k = 0;
        while (k < idx) {
            if (m.find(arr1[k]) == m.end()) {
                swap(arr1[k], arr1[--idx]);
            } else {
                arr1[k] = m[arr1[k]];
                k++;
            }
        }

        sort(arr1.begin()+idx, arr1.end());
        sort(arr1.begin(), arr1.begin()+idx);

        for (int i = 0; i < idx; i++) {
            arr1[i] = arr2[arr1[i]];
        }
        
        return arr1;
    }
};
