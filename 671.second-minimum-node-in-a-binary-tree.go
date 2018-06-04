/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findSecondMinimumValue(root *TreeNode) int {
	const intMax = 1<<63 - 1
	res := intMax
	res = findSecondMinimumValueHelper(root, root.Val, res)
	if res == intMax {
		return -1
	}
	return res

}

func findSecondMinimumValueHelper(root *TreeNode, l int, r int) int {
	if root == nil {
		return r
	}

	if l < root.Val && root.Val < r {
		r = root.Val
	}
	r = findSecondMinimumValueHelper(root.Left, l, r)
	r = findSecondMinimumValueHelper(root.Right, l, r)
	return r
}
