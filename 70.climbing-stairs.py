class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        data = [ 0 for i in range(n+3) ]
        data[1] = 1
        data[2] = 2

        for i in range(3, n+1):
            data[i] = data[i-1] + data[i-2]

        return data[n]
        
