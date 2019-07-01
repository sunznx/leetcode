class Solution {

    private $parent;

    function find($x)
    {
        if (!isset($this->parent[$x])) {
            $this->parent[$x] = $x;
        }

        if ($this->parent[$x] != $x) {
            return $this->find($this->parent[$x]);
        }
        return $this->parent[$x];
    }

    /**
     * @param Integer[][] $edges
     * @return Integer[]
     */
    function findRedundantConnection($edges) {
        foreach ($edges as $edge) {
            list($x, $y) = $edge;
            
            $parentX = $this->find($x);
            $parentY = $this->find($y);
            
            if ($parentY != $parentX) {
                $this->parent[$parentY] = $parentX;
            } else {
                return $edge;
            }
        }
    }
}
