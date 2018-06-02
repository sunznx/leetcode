func isVowel(c uint8) bool {
	switch c {
	case 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U':
		return true;
	}

	return false;
}

func toGoatLatin(s string) string {
	var arr = strings.Split(s, " ")
	for i := range arr {
		postfix := "ma" + strings.Repeat("a", i+1)
		if isVowel(arr[i][0]) {
			arr[i] = arr[i] + postfix
		} else {
			arr[i] = arr[i][1:] + arr[i][0:1] + postfix
		}
	}

	return strings.Join(arr, " ")
}
