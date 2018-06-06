func min(a int, b int) int {
	if a < b {
		return a
	}

	return b
}

func abs(a int) int {
	if a >= 0 {
		return a
	}
	return -a
}

func containsNearbyDuplicate(nums []int, k int) bool {
	res := len(nums)

	for i := 0; i < len(nums); i++ {
		for j := i+1; j < len(nums); j++ {
			if nums[i] == nums[j] {
				res = min(abs(j-i), res)
			}
		}
	}

	return res <= k && len(nums) >= 2 && res < len(nums)
}
