func hammingDistance(x int, y int) int {
	res := (x ^ y)
	
	return countBit(res)
}

func countBit(num int) int {
	res := 0
	for num != 0 {
		num = (num & (num-1))
		res += 1
	}
	return res
}
