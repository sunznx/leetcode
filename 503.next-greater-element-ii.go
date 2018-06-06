func max(a int, b int) int {
	if a > b {
		return a
	}

	return b
}

func nextGreaterElements(nums []int) []int {
	var v []int
	if len(nums) == 0 {
		return v
	}

	maxn := nums[0]

	for i := 0; i < len(nums); i++ {
		maxn = max(maxn, nums[i])
	}

	for i := 0; i < len(nums); i++ {
		found := false

		if found == false {
			if maxn == nums[i] {
				v = append(v, -1)
				found = true
			}
		}

		if found == false {
			for j := i+1; j < len(nums); j++ {
				if nums[j] > nums[i] {
					v = append(v, nums[j])
					found = true
					break
				}
			}
		}

		if found == false {
			for j := 0; j < i; j++ {
				if nums[j] > nums[i] {
					v = append(v, nums[j])
					found = true
					break
				}
			}
		}

		if found == false {
			v = append(v, -1)
		}
	}

	return v
}
