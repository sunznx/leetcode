class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function majorityElement($nums) {
        $l = 0;
        $r = count($nums)-1;
        $mid = (int)(count($nums)/2);

        while (true) {
            $p = $this->partition($nums, $l, $r);
            if ($p == $mid) {
                return $nums[$p];
            } else if ($p < $mid) {
                $l = $p + 1;
            } else {
                $r = $p - 1;
            }
        }
    }

    function qsort($nums)
    {
        $this->qsortHelper($nums, 0, count($nums)-1);
        return $nums;
    }

    function qsortHelper(&$nums, $l, $r)
    {
        if ($l >= $r) {
            return;
        }

        $p = $this->partition($nums, $l, $r);
        $this->qsortHelper($nums, $l, $p-1);
        $this->qsortHelper($nums, $p+1, $r);
    }

    function partition(&$nums, $l, $r)
    {
        if ($l == $r) {
            return $l;
        }

        $x = $nums[$r];
        $i = $l;
        $j = $r-1;
        while ($i <= $j) {
            if ($nums[$i] < $x) {
                $i += 1;
            } else {
                $this->swap($nums, $i, $j);
                $j -= 1;
            }
        }
        $this->swap($nums, $i, $r);
        return $i;
    }

    function swap(&$nums, $i, $j)
    {
        $t = $nums[$i];
        $nums[$i] = $nums[$j];
        $nums[$j] = $t;
    }
}
