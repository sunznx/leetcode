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
     * @param Integer[] $preorder
     * @return TreeNode
     */
    function bstFromPreorder($preorder) {
        return $this->bstFromPreorderHelp($preorder);
    }
    
    function bstFromPreorderHelp($preorder) {
        if (empty($preorder)) {
            return null;
        }

        $root = new TreeNode($preorder[0]);
        
        $s1 = [];
        $s2 = [];
        
        for ($i = 1; $i < count($preorder); $i++) {
            if ($preorder[$i] < $preorder[0]) {
                $s1[] = $preorder[$i];
            } else {
                $s2[] = $preorder[$i];
            }
        }
        
        $root->left = $this->bstFromPreorderHelp($s1);
        $root->right = $this->bstFromPreorderHelp($s2);
        return $root;
    }
}
