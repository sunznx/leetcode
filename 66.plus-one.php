// CreateTime: 2019-12-02 17:12:48
class Solution {

    /**
     * @param Integer[] $digits
     * @return Integer[]
     */
    function plusOne($digits) {
        $len = count($digits);
        for ($i = $len-1; $i >= 0; $i--) {
            if ($digits[$i] == 9) {
                $digits[$i] = 0;
            } else {
                $digits[$i] += 1;
                return $digits;
            }
        }
        
        array_unshift($digits, 1);
        return $digits;
    }
}
