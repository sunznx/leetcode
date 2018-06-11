func normalize(str string) string {
	return strings.ToLower(strings.TrimRight(str, "!?',;."))
}

func mostCommonWord(paragraph string, banned []string) string {
	m := make(map[string]int)
	ban := make(map[string]bool)

	for i := 0; i < len(banned); i++ {
		str := normalize(banned[i])
		ban[strings.ToLower(str)] = true
	}

	arr := strings.Split(paragraph, " ")

	res := ""
	maxn := 0

	for i := 0; i < len(arr); i++ {
		str := normalize(arr[i])
		_, ok := ban[str]
		if ok {
			continue
		}

		m[str] += 1

		if m[str] > maxn {
			maxn = m[str]
			res = str
		}
	}

	return res
}
