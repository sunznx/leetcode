// CreateTime: 2021-01-10 10:31:03
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> arr(encoded.size()+1);
        arr[0] = first;

        for (int i = 0; i < encoded.size(); i++) {
            if (i == 0) {
                arr[i+1] = (encoded[i] ^ first);
            } else {
                arr[i+1] = (encoded[i] ^ arr[i]);
            }
        }

        return arr;
    }
};