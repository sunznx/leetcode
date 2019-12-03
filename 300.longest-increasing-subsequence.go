package main

func max(num1 int, num2 int) int {
	if num1 > num2 {
		return num1
	}
	return num2
}

func lengthOfLIS(nums []int) int {
	l := len(nums)

	if l == 0 {
		return 0
	}

	f := make([]int, l)

	f[0] = 1
	ans := f[0]

	for i := 1; i < l; i++ {
		f[i] = 1
		for j := 0; j < i; j++ {
			if nums[j] < nums[i] {
				f[i] = max(f[i], f[j]+1)
			}
		}

		ans = max(ans, f[i])
	}

	return ans
}
