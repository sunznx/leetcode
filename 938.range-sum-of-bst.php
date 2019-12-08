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
        $this->dfs($root, $L, $R);
        return $this->res;
    }
    
    function dfs($root, $l, $r) {
        if (empty($root)) {
            return;
        }
        
        if ($root->val < $l) {
            $this->dfs($root->right, $l, $r);
        } else if ($root->val > $r) {
            $this->dfs($root->left, $l, $r);
        } else {
            $this->res += $root->val;
            $this->dfs($root->left, $l, $r);
            $this->dfs($root->right, $l, $r);
        }
    }
}
