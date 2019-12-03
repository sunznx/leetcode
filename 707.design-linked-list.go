type MyLinkedList struct {
	head *Node
	len  int
}

type Node struct {
	val  int
	Next *Node
}

func (this *MyLinkedList) NewNode(val int) *Node {
	this.len += 1
	return &Node{
		val: val,
	}
}

/** Initialize your data structure here. */
func Constructor() MyLinkedList {
	return MyLinkedList{
		head: &Node{},
		len:  0,
	}
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
func (this *MyLinkedList) Get(index int) int {
	if index < 0 || index >= this.len {
		return -1
	}

	p := this.head.Next
	for i := 0; i < index; i++ {
		p = p.Next
	}
	return p.val
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
func (this *MyLinkedList) AddAtHead(val int) {
	node := this.NewNode(val)
	node.Next = this.head.Next
	this.head.Next = node
}

/** Append a node of value val to the last element of the linked list. */
func (this *MyLinkedList) AddAtTail(val int) {
	p := this.head
	for p.Next != nil {
		p = p.Next
	}
	node := this.NewNode(val)
	p.Next = node
}

/** Add a node of value val before the index-th node in the linked list.
If index equals to the length of linked list, the node will be appended to the end of linked list.
// If index is greater than the length, the node will not be inserted. */
func (this *MyLinkedList) AddAtIndex(index int, val int) {
	if this.len < index {
		return
	}

	if this.len == index {
		this.AddAtTail(val)
		return
	}

	p := this.head
	for i := 0; i < index; i++ {
		p = p.Next
	}

	node := this.NewNode(val)
	if p.Next != nil {
		node.Next = p.Next
	}
	p.Next = node
}

/** Delete the index-th node in the linked list, if the index is valid. */
func (this *MyLinkedList) DeleteAtIndex(index int) {
	if index < 0 || this.len <= index {
		return
	}

	p := this.head
	for i := 0; i < index; i++ {
		p = p.Next
	}

	if p.Next != nil {
		p.Next = p.Next.Next
	}

	this.len -= 1
}
