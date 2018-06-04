func realIsPalindrome(s string) bool {
	for i := 0; i < len(s)/2; i++ {
		if s[i] != s[len(s)-1-i] {
			return false
		}
	}

	return true
}

func isPalindrome(s string) bool {
	t := ""
	for i := 0; i < len(s); i++ {
		if 'A' <= s[i] && s[i] <= 'Z' {
			t += string(s[i] - 'A' + 'a')
		}
		if 'a' <= s[i] && s[i] <= 'z' || '0' <= s[i] && s[i] <= '9' {
			t += string(s[i])
		}
	}

	return realIsPalindrome(t)
}
