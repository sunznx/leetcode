//package main
//
//import "fmt"
//
//type TreeNode struct {
//	Val   int
//	Left  *TreeNode
//	Right *TreeNode
//}
//
//var null = -1 << 63
//
//func Ints2TreeNode(ints []int) *TreeNode {
//	n := len(ints)
//	if n == 0 {
//		return nil
//	}
//
//	root := &TreeNode{
//		Val: ints[0],
//	}
//
//	queue := make([]*TreeNode, 1, n*2)
//	queue[0] = root
//
//	i := 1
//	for {
//		node := queue[0]
//		queue = queue[1:]
//
//		if i < n && ints[i] != null {
//			node.Left = &TreeNode{Val: ints[i]}
//			queue = append(queue, node.Left)
//		}
//		i++
//
//		if i < n && ints[i] != null {
//			node.Right = &TreeNode{Val: ints[i]}
//			queue = append(queue, node.Right)
//		}
//		i++
//
//		if i >= n {
//			break
//		}
//	}
//
//	return root
//}
//
//func show(node *TreeNode) {
//	if node == nil {
//		return
//	}
//	fmt.Printf("%v\n", node.Val)
//	show(node.Left)
//	show(node.Right)
//}
//
//func main() {
//	//show(convertBST(Ints2TreeNode([]int{5, 2, 13})))
//	//fmt.Printf("--------------\n")
//	//show(convertBST(Ints2TreeNode([]int{0,-1,2,-3,null,null,4})))
//	//fmt.Printf("--------------\n")
//	//show(convertBST(Ints2TreeNode([]int{1, 2})))
//	//fmt.Printf("--------------\n")
//	show(convertBST(Ints2TreeNode([]int{2, 0, 3, -4, 1})))
//}
//
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func convertBST(root *TreeNode) *TreeNode {
	sum := 0
	return convertBSTHelp(root, &sum)
}

func convertBSTHelp(root *TreeNode, x *int) *TreeNode {
	if root == nil {
		return root
	}

	root.Right = convertBSTHelp(root.Right, x)
	*x += root.Val
	root.Val = *x
	root.Left = convertBSTHelp(root.Left, x)

	return root
}
