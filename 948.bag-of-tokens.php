class Solution {

    /**
     * @param Integer[] $tokens
     * @param Integer $P
     * @return Integer
     */
    function bagOfTokensScore($tokens, $P) {
        $score = 0;
        sort($tokens);

        $n = count($tokens);
        $i = 0;
        $j = $n - 1;
        while ($n > 0) {
            if ($P >= $tokens[$i]) {
                $P -= $tokens[$i];
                $score += 1;
                $n -= 1;
                $i += 1;
                continue;
            }

            if ($P < $tokens[$i] && $score > 0 && $n >= 3) {
                $P += $tokens[$j];
                $score -= 1;
                $n -= 1;
                $j -= 1;
                continue;
            }
            break;
        }
        return $score;
    }
}
