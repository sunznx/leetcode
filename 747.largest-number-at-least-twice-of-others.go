func dominantIndex(nums []int) int {
	max1 := nums[0]
	max2 := nums[0]
	x := 0
	y := 0

	findMax1 := false
	findMax2 := false
	for i := 0; i < len(nums); i++ {
		if findMax1 == false {
			findMax1 = true
			x = i
			max1 = nums[i]
		} else if nums[i] > max1 {
			max2 = max1
			y = x
			x = i
			max1 = nums[i]
			findMax2 = true
		} else if findMax2 == false {
			findMax2 = true
			y = i
			max2 = nums[i]
		} else if nums[i] > max2 {
			findMax2 = true
			y = i
			max2 = nums[i]
		}
	}

	if nums[x] >= nums[y]*2 || findMax2 == false {
		return x
	}

	return -1
}
