public class Solution {
    public int countPrimes(int n) {
        int [] a = new int [n+1];
        int [] ans = new int [n+1];

        boolean [] prime = new boolean [n+1];
        for (int i = 2; i < n; i++) {
            prime[i] = true;
        }

        int count = 0;

        for (int i = 2; i < n; i++) {
            if (prime[i] == true) {
                ans[count++] = i;
                for (int j = 2*i; j < n; j+=i) {
                    prime[j] = false;
                }
            }
        }


        return count;
    }
}
