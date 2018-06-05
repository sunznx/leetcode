/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pathSum(root *TreeNode, sum int) int {
	if root == nil {
		return 0
	}

	cnt := 0
	pathSumHelp(root, sum, &cnt)
	return cnt + pathSum(root.Left, sum) + pathSum(root.Right, sum)
}

func pathSumHelp(root *TreeNode, sum int, cnt *int) {
	if root == nil {
		return
	}

	if sum == root.Val {
		*cnt = *cnt + 1
	}

	pathSumHelp(root.Left, sum-root.Val, cnt)
	pathSumHelp(root.Right, sum-root.Val, cnt)
}



