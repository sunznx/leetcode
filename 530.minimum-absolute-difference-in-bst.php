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

    public $parent;
    public $res;

    /**
     * @param TreeNode $root
     * @return Integer
     */
    function getMinimumDifference($root) {
        $this->getMinimumDifferenceHelper($root);
        return $this->res;
    }

    function getMinimumDifferenceHelper($root) {
        if (empty($root)) {
            return $this->res;
        }

        if ($root->left) {
            $this->getMinimumDifferenceHelper($root->left);
        }
        if (!empty($this->parent)) {
            $this->min($root->val - $this->parent->val);
        }
        $this->parent = $root;
        if ($root->right) {
            $this->getMinimumDifferenceHelper($root->right);
        }
    }

    function min($val)
    {
        if ($this->res === null) {
            $this->res = $val;
        }
        $this->res = min($this->res, $val);
    }
}
