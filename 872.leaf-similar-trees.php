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
     * @param TreeNode $root1
     * @param TreeNode $root2
     * @return Boolean
     */
    function leafSimilar($root1, $root2) {
        $leaf1 = $this->getLeaf($root1);
        $leaf2 = $this->getLeaf($root2);
        
        if (count($leaf1) != count($leaf2)) {
            return false;
        }
        
        for ($i = 0; $i < count($leaf1); $i++) {
            if ($leaf1[$i] != $leaf2[$i]) {
                return false;
            }
        }

        return true;
    }
    
    function getLeaf($root)
    {
        return $this->getLeafHelp($root, []);
    }
    
    function getLeafHelp($root, $res)
    {
        if (empty($root)) {
            return $res;
        }
        
        if (!empty($root->left)) {
            $res = $this->getLeafHelp($root->left, $res);
        }
        
        if (!empty($root->right)) {
            $res = $this->getLeafHelp($root->right, $res);
        }
        
        if (empty($root->left) && empty($root->right)) {
            $res[] = $root->val;
        }
        return $res;
    }
}
