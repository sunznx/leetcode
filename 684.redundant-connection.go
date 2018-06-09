func findRedundantConnection(edges [][]int) []int {
	N := len(edges)

	var parent = make([]int, N+1)
	var size = make([]int, N+1)

	uf_init(parent, size)

	var res = make([]int, 2)

	for i := 0; i < N; i++ {
		x := edges[i][0]
		y := edges[i][1]

		if uf_connected(parent, x, y) {
			res[0] = x
			res[1] = y
		} else {
			uf_add(parent, size, x, y)
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

func uf_add(parent []int, size []int, x int, y int) {
	i := uf_find(parent, x)
	j := uf_find(parent, y)

	if i == j {
		return
	}

	if size[i] > size[j] {
		parent[j] = i
		size[i] += size[j]
	} else {
		parent[i] = j
		size[j] += size[i]
	}
}

func uf_find(parent []int, x int) int {
	for x != parent[x] {
		x = parent[x]
	}

	return x
}

func uf_connected(parent []int, x int, y int) bool {
	return uf_find(parent, x) == uf_find(parent, y)
}
