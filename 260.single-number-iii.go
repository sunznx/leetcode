func singleNumber(nums []int) []int {
	var res []int
	for i := 0; i < len(nums); i++ {
		ok := true
		for j := 0; j < len(nums); j++ {
			if i == j {
				continue;
			}
			if nums[i] == nums[j] {
				ok = false
				break
			}
		}

		if ok {
			res = append(res, nums[i])
		}
	}

	return res
}
