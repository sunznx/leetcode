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
     * @param String[][] $accounts
     * @return String[][]
     */
    function accountsMerge($accounts) {
        $nameMap = [];
        foreach ($accounts as $account) {
            $name = array_shift($account);
            $p0 = $this->find($account[0]);
            foreach ($account as $email) {
                $nameMap[$email] = $name;

                $p = $this->find($email);
                if ($p != $p0) {
                    $this->parent[$p] = $p0;
                }
            }
        }

        // 收敛
        foreach ($this->parent as $email => $p) {
            $this->parent[$email] = $this->find($p);
        }

        $map = [];
        foreach ($this->parent as $email => $p) {
            if ($email != $p) {
                $map[$p][] = $email;
            } else {
                $map[$p][] = $p;
            }
        }

        $res = [];
        foreach ($map as $p => $emailList) {
            array_unshift($emailList, $nameMap[$p]);
            sort($emailList);
            $res[] = $emailList;
        }
        return $res;
    }
}
