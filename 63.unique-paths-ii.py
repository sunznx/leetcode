class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """

        n = len(obstacleGrid)
        m = len(obstacleGrid[0])
            

        dp = [0] * n
        for i in range(0, n):
            dp[i] = [0] * m

        for i in range(0, n):
            for j in range(0, m):
                if obstacleGrid[i][j] == 1:
                    dp[i][j] = 0
                else:    
                    if i == 0 and j == 0:
                        dp[i][j] = 1
                    elif i == 0:
                        dp[i][j] = dp[i][j-1]
                    elif j == 0:
                        dp[i][j] = dp[i-1][j]
                    else:
                        dp[i][j] = dp[i-1][j] + dp[i][j-1]

        return dp[n-1][m-1]
