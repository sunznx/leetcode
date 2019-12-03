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
     * @param Integer $x
     * @param Integer $y
     * @return Boolean
     */
    function isCousins($root, $x, $y) {
        $q = [$root];
        $parent = [];
        $parent[$root->val] = null;

        while (!empty($q)) {
            $newQ = [];
            $findX = false;
            $findY = false;
            $parentX = null;
            $parentY = null;

            foreach ($q as $node) {
                if ($node->left) {
                    $newQ[] = $node->left;
                    $parent[$node->left->val] = $node->val;
                }
                if ($node->right) {
                    $newQ[] = $node->right;
                    $parent[$node->right->val] = $node->val;
                }

                if ($node->val == $x) {
                    $findX = true;
                    $parentX = $parent[$node->val];
                }
                if ($node->val == $y) {
                    $findY = true;
                    $parentY = $parent[$node->val];
                }
            }


            if ($findX && $findY && $parentX != $parentY) {
                return true;
            }

            if ($findX || $findY) {
                return false;
            }

            $q = $newQ;
        }

        return false;
    }
}
