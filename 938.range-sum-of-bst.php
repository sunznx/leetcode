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
    public $res = 0;

    /**
     * @param TreeNode $root
     * @param Integer $L
     * @param Integer $R
     * @return Integer
     */
    function rangeSumBST($root, $L, $R) {
        $this->rangeSumBSTHelp($root, $L, $R);
        return $this->res;
    }
    
    function rangeSumBSTHelp($root, $L, $R) {
        if (empty($root)) {
            return;
        }
        
        if ($root->val < $L && empty($root->right)) {
            return;
        }
        
        if ($root->val > $R && empty($root->left)) {
            return;
        }
        
        if (!empty($root->left)) {
            $this->rangeSumBSTHelp($root->left, $L, $R);
        }
        
        if ($L <= $root->val && $root->val <= $R) {
            $this->res += $root->val;
        }

        if (!empty($root->right)) {
            $this->rangeSumBSTHelp($root->right, $L, $R);
        }
    }
}
