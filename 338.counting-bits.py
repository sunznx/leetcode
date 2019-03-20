class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        res = [0] * (num+1)
        k = 0
        while True:
            n = (1 << k)

            if n > num:
                break

            res[n] = 1
            k += 1


        for i in range(2, k+1):
            start = (1 << (i-1))
            end = min((1 << i), num+1)

            for j in range(start, end):
                mask = (j & (~(1 << (i-1))))
                res[j] = res[mask] + 1

        return res
