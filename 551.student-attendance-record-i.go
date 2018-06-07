// A student could be rewarded if his attendance record
// doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).
func checkRecord(s string) bool {
	A := 0
	L := 0

	for i := 0; i < len(s); i++ {
		if s[i] == 'L' {
			L += 1
		} else {
			L = 0
			if s[i] == 'A' {
				A += 1
			}
		}

		if A > 1 || L > 2 {
			return false
		}

	}

	return true
}
