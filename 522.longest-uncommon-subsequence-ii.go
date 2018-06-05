func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

func findLUSlength(strs[] string) int {
	res := -1

	for i := 0; i < len(strs); i++ {
		j := 0
		for ; j < len(strs); j++ {
			if i == j {
				continue
			}
			if isSubSequence(strs[i], strs[j]) {
				break
			}
		}

		if j == len(strs) {
			res = max(res, len(strs[i]))
		}
	}

	return res
}

func isSubSequence(s1 string, s2 string) bool {
	if len(s1) > len(s2) {
		return false
	}

	index := 0
	for i := 0; i < len(s2); i++ {
		if s1[index] == s2[i] {
			index += 1
		}
		if index == len(s1) {
			return true
		}
	}

	return false
}
