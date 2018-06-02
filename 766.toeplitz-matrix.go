func isToeplitzMatrix(matrix [][]int) bool {
	raw := len(matrix)
	col := len(matrix[0])

	for i := 0; i < raw; i++ {
		for j := 0; j < col; j++ {
			x := i+1
			y := j+1
			if !(x >= raw || y >= col || matrix[i][j] == matrix[x][y]) {
				return false
			}
		}
	}

	return true
}

