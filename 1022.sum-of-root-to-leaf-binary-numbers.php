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
     * @return Integer
     */
    function sumRootToLeaf($root) {
        $this->sumRootToLeafHelp($root, 0);
        return $this->res;
    }
    
    function sumRootToLeafHelp($root, $prev) {
        if (empty($root)) {
            return;
        }

        $cur = $prev * 2 + $root->val;
        
        if (!empty($root->left)) {
            $this->sumRootToLeafHelp($root->left, $cur);
        }
        
        if (!empty($root->right)) {
            $this->sumRootToLeafHelp($root->right, $cur);
        }
        
        if (empty($root->left) && empty($root->right)) {
            $this->res += $cur;
        }
    }
}
