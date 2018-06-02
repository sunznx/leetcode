func majorityElement(nums []int) int {
	res := nums[0]
	count := 0
	for i := 0; i < len(nums); i++ {
		if count == 0 {
			res = nums[i]
			count = 1
		} else {
			if nums[i] == res {
				count++
			} else {
				count--
			}
		}
	}

	return res
}

// solution 1
//func swap(nums [] int, i int, j int) {
//	x := nums[i]
//	nums[i] = nums[j]
//	nums[j] = x
//}
//
//func partition(nums []int, l int, r int) int {
//	x := nums[r]
//	i := l
//	j := r - 1
//	for i <= j {
//		if nums[i] <= x {
//			i++
//		} else {
//			swap(nums, i, j)
//			j--
//		}
//	}
//
//	swap(nums, r, i)
//	return i
//}
//
//func majorityElement(nums []int) int {
//	l := 0
//	r := len(nums) - 1
//	for {
//		q := partition(nums, l, r)
//		if q == len(nums)/2 {
//			return nums[q]
//		} else if q > len(nums)/2 {
//			r = q - 1
//		} else if q < len(nums)/2 {
//			l = q + 1
//		}
//	}
//
//	return -1
//}

// solution 0
//func majorityElement(nums []int) int {
//	sort.Ints(nums)
//	return nums[len(nums)/2]
//}
