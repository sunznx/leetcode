//package main
//
//import (
//	"strconv"
//	"fmt"
//)
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
//	show(node.Left)
//	fmt.Printf("%v\n", node.Val)
//	show(node.Right)
//}
//
//func main() {
//	fmt.Printf("%v\n", tree2str(Ints2TreeNode([]int{1,2,3,4})))
//	fmt.Printf("%v\n", tree2str(Ints2TreeNode([]int{1,2,3,null,4})))
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
func tree2str(root *TreeNode) string {
	if root == nil {
		return ""
	}

	val := strconv.Itoa(root.Val)
	if  root.Left == nil && root.Right == nil{
		return val
	}
	val += "(" + tree2str(root.Left) + ")"
	if root.Right != nil {
		val += "(" + tree2str(root.Right) + ")"
	}

	return val
}
