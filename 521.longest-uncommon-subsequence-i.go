func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func findLUSlength(a string, b string) int {
	len1 := len(a)
	len2 := len(b)

	if len1 != len2 {
		return max(len1, len2)
	}

	if a == b {
		return -1
	}

	return len1
}
