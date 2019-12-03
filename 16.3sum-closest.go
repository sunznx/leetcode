func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func threeSumClosest(nums []int, target int) int {
	selected := []int{nums[0], nums[1], nums[2]}
	res := selected[0] + selected[1] + selected[2]
	dfs(nums, selected, 0, 0, target, &res)
	return res
}

func dfs(nums []int, selected []int, from int, step int, target int, res *int) {
	if step == 3 {
		t := selected[0] + selected[1] + selected[2]
		if abs(t - target) < abs(*res - target) {
			*res = t
		}
		return
	}

	for i := from; i < len(nums); i++ {
		selected[step] = nums[i]
		dfs(nums, selected, i+1, step + 1, target, res)
	}
}
