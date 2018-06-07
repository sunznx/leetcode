func isRectangleOverlap(rec1 []int, rec2 []int) bool {
	x11 := rec1[0]
	y11 := rec1[1]
	x21 := rec1[2]
	y21 := rec1[3]


	x12 := rec2[0]
	y12 := rec2[1]
	x22 := rec2[2]
	y22 := rec2[3]

	return ! (x11 >= x22 || x21 <= x12 || y11 >= y22 || y21 <= y12)
}
