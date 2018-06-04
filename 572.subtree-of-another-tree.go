/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSubtree(s *TreeNode, t *TreeNode) bool {
	return isSubtreeHelp(s, t, false)
}

func isSubtreeHelp(s *TreeNode, t *TreeNode, hasParent bool) bool {
	if s == nil && t == nil {
		return true
	}

	if (s == nil && t != nil) || (s != nil && t == nil) {
		return false
	}

	if s.Val != t.Val {
		if hasParent {
			return false
		}
		return isSubtreeHelp(s.Left, t, false) || isSubtreeHelp(s.Right, t, false)
	}

	if s.Val == t.Val {
		return (isSubtreeHelp(s.Left, t.Left, true) && isSubtreeHelp(s.Right, t.Right, true)) ||
			isSubtreeHelp(s.Left, t, false) || isSubtreeHelp(s.Right, t, false)
	}

	return false

}
