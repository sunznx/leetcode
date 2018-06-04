func findRestaurant(list1 []string, list2 []string) []string {
	var res []string

	minStep := len(list1) + len(list2)
	for i := 0; i < len(list1); i++ {
		for j := 0; j < len(list2); j++ {
			if list1[i] == list2[j] {
				if i + j == minStep {
					res = append(res, list1[i])					
				} else if (i + j < minStep) {
					res = []string{list1[i]}
					minStep = i + j
				}
			}
		}
	}

	return res
}
