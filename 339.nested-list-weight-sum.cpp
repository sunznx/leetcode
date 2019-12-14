// CreateTime: 2019-12-13 19:25:27
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int ans = 0;

    int depthSum(vector<NestedInteger>& nestedList) {
        depthSum(nestedList, 1);
        return ans;
    }
    
    void depthSum(vector<NestedInteger>& nestedList, int dep) {
        int len = nestedList.size();
        for (int i = 0; i < len; i++) {
            if (nestedList[i].isInteger()) {
                ans += nestedList[i].getInteger() * dep;
            } else {
                depthSum(nestedList[i].getList(), dep+1);
            }
        }
    }
};