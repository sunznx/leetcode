func swap(nums [] int, i int, j int) {
	x := nums[i]
	nums[i] = nums[j]
	nums[j] = x
}

func partition(nums []int, l int, r int) int {
	x := nums[r]
	i := l
	j := r - 1
	for i <= j {
		if nums[i] <= x {
			i++
		} else {
			swap(nums, i, j)
			j--
		}
	}

	swap(nums, r, i)
	return i
}

func majorityElement(nums []int) int {
	l := 0
	r := len(nums) - 1
	for {
		q := partition(nums, l, r)
		if q == len(nums)/2 {
			return nums[q]
		} else if q > len(nums)/2 {
			r = q - 1
		} else if q < len(nums)/2 {
			l = q + 1
		}
	}

	return -1
}

//func majorityElement(nums []int) int {
//	sort.Ints(nums)
//	return nums[len(nums)/2]
//}
