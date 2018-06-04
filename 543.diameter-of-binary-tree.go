/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func diameterOfBinaryTree(root *TreeNode) int {
	if root == nil {
		return 0
	}

	res := 0
	depth(root, &res)

	return res
}

func depth(root *TreeNode, res *int) int {
	if root == nil {
		return 0
	}

	left := depth(root.Left, res)
	right := depth(root.Right, res)

	*res = max(*res, left + right)

	return max(left, right) + 1
}

func max(a int, b int) int {
	if a > b {
		return a
	}

	return b
}
