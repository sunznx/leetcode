/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     public $val = null;
 *     public $left = null;
 *     public $right = null;
 *     function __construct($value) { $this->val = $value; }
 * }
 */
class Solution {
    /**
     * @param TreeNode $root
     * @return Boolean
     */
    function isUnivalTree($root) {
        if (empty($root)) {
            return true;
        }
        return $this->isUnivalTreeHelp($root, $root->val);
    }

    function isUnivalTreeHelp($root, $val) {
        if (empty($root)) {
            return true;
        }

        if ($root->val != $val) {
            return false;
        }

        return $this->isUnivalTreeHelp($root->left, $val) && $this->isUnivalTreeHelp($root->right, $val);
    }
}
