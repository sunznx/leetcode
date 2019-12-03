class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Integer
     */
    function findPairs($nums, $k) {
        $cnt = count($nums);
        if ($cnt == 0) {
            return 0;
        }

        sort($nums);
        $res = 0;
        for ($i = 0; $i < $cnt-1; $i++) {
            if ($i > 0 && $nums[$i] == $nums[$i-1]) {
                continue;
            }

            for ($j = $i+1; $j < $cnt; $j++) {
                if ($nums[$i] + $k < $nums[$j]) {
                    break;
                }
                if ($nums[$i] + $k == $nums[$j]) {
                    $res += 1;
                    break;
                }
            }
        }

        return $res;
    }
}
