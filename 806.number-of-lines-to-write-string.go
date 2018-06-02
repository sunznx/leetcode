func numberOfLines(widths []int, S string) []int {
	lines := 0
	count := 0
	lastCount := 0
	for i := 0; i < len(S); i++ {
		count += widths[S[i]-'a']
		if i == 0 || count > 100 {
			count = widths[S[i]-'a']
			lines++
		}
		lastCount = count
	}

	return []int{lines, lastCount}
}
