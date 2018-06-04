func distributeCandies(candies []int) int {
	sort.Ints(candies)

	res := 1
	for i := 1; i < len(candies) && res < len(candies)/2; i++ {
		if candies[i] != candies[i-1] {
			res += 1
		}
	}

	return res
}
