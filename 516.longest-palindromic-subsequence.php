class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function longestPalindromeSubseq($s) {
        $n = strlen($s);

        if ($n <= 1) {
            return $n;
        }

        $dp = array_fill(0, $n, array_fill(0, $n, 0));
        for ($i = 0; $i < $n; $i++) {
            $dp[$i][$i] = 1;
            for ($j = $i-1; $j >= 0; $j--) {
                if ($s[$i] == $s[$j]) {
                    $dp[$j][$i] = $dp[$j+1][$i-1] + 2;
                } else {
                    $dp[$j][$i] = max($dp[$j][$i-1], $dp[$j+1][$i]);
                }
            }
        }
        
        return $dp[0][$n-1];
    }
}
