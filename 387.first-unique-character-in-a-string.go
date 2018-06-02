func firstUniqChar(s string) int {
	arr := [26]int{0}
	for i := 0; i < len(s); i++ {
		arr[s[i]-'a'] += 1
	}
	for i := 0; i < len(s); i++ {
		if arr[s[i]-'a'] == 1 {
			return i
		}
	}

	return -1
}
