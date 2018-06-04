func matrixReshape(nums [][]int, r int, c int) [][]int {
	raw := len(nums)
	col := len(nums[0])

	if c*r != raw*col {
		return nums
	}

	res := make([][]int, r)
	for i := 0; i < r; i++ {
		res[i] = make([]int, c)
		for j := 0; j < c; j++ {
			res[i][j] = nums[(i*c+j)/col][(i*c+j)%col]
		}
	}

	return res
}
