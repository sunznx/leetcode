func numMagicSquaresInside(grid [][]int) int {
	res := 0
	raw := len(grid)
	col := len(grid[0])

	for i := 0; i < raw-2; i++ {
		for j := 0; j < col-2; j++ {
			if check(grid, i, j) {
				res += 1
			}
		}
	}

	return res
}

func check(grid [][]int, x int, y int) bool {
	v := make([]bool, 20)
	cnt := 0
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if v[grid[x+i][y+j]] || grid[x+i][y+j] >= 10 || grid[x+i][y+j] <= 0 {
				return false
			}
			v[grid[x+i][y+j]] = true
			cnt += 1
		}
	}

	if cnt != 9 {
		return false
	}

	
	v1 := grid[x][y] + grid[x][y+1] + grid[x][y+2]
	v2 := grid[x+1][y] + grid[x+1][y+1] + grid[x+1][y+2]
	v3 := grid[x+2][y] + grid[x+2][y+1] + grid[x+2][y+2]
	
	v4 := grid[x][y] + grid[x+1][y] + grid[x+2][y]
	v5 := grid[x][y+1] + grid[x+1][y+1] + grid[x+2][y+1]
	v6 := grid[x][y+2] + grid[x+1][y+2] + grid[x+2][y+2]
	
	v7 := grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2]
	v8 := grid[x+2][y] + grid[x+1][y+1] + grid[x][y+2]

	return v1 == 15 &&
		v2 == 15 && 
		v3 == 15 && 
		v4 == 15 && 
		v5 == 15 && 
		v6 == 15 && 
		v7 == 15 && 
		v8 == 15 
}
