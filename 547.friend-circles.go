func findCircleNum(M [][]int) int {
	row := len(M)
	col := len(M[0])

	var parent = make([]int, row)
	var size = make([]int, row)

	res := row

	uf_init(parent, size)

	for i := 0; i < row; i++ {
		for j := i+1; j < col; j++ {
			if M[i][j] == 1 {
				uf_add(parent, size, i, j, &res)
			}
		}
	}

	return res
}

func uf_init(parent []int, size []int) {
	for i := 0; i < len(parent); i++ {
		parent[i] = i
	}

	for i := 0; i < len(size); i++ {
		size[i] = 1
	}
}

func uf_add(parent []int, size []int, i int, j int, res *int) {
	px := uf_find(parent, i)
	py := uf_find(parent, j)

	if px == py {
		return;
	}

	if size[px] > size[py] {
		parent[py] = px
		size[px] += size[py]
	} else {
		parent[px] = py
		size[py] += size[px]
	}


	*res = *res - 1
}

func uf_find(parent []int, x int) int {
	for x != parent[x] {
		x = parent[x]
	}

	return x
}
