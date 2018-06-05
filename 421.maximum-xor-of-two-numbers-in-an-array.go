func max(a int, b int) int {
	if a > b {
		return a
	}
	
	return b
}

func findMaximumXOR(nums []int) int {
	res := 0
	for i := 0; i < len(nums)-1; i++ {
		for j := i+1; j < len(nums); j++ {
			res = max(res, (nums[i]^nums[j]))
		}
	}
	
	return res
}
