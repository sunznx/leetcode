class Solution {

    private $res;

    /**
     * @param Integer $n
     * @return String[]
     */
    function generateParenthesis($n) {
        $this->dfs($n, 0, 0, "");
        return $this->res;
    }
    
    function dfs($n, $l, $r, $v)
    {
        if ($l > $n) {
            return;
        }
        
        if ($r == $n) {
            $this->res[] = $v;
            return;
        }
        
        if ($l == $r) {
            $this->dfs($n, $l+1, $r, $v . "(");
            return;
        }
        
        $this->dfs($n, $l+1, $r, $v . "(");
        $this->dfs($n, $l, $r+1, $v . ")");
    }
}
