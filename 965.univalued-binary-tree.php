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

    public $v;

    /**
     * @param TreeNode $root
     * @return Boolean
     */
    function isUnivalTree($root) {
        if (empty($root)) {
            return true;
        }
        $this->v = $root->val;
        return $this->isUnivalTreeHelp($root);
    }
    
    function isUnivalTreeHelp($root) {
        if (empty($root)) {
            return true;
        }
        
        if ($root->val != $this->v) {
            return false;
        }

        return $this->isUnivalTreeHelp($root->left) && $this->isUnivalTreeHelp($root->right);
    }
}
