class NumArray(object):
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.aux = []
        tot = 0

        for n in nums:
            tot += n
            self.aux.append(tot)


    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        if i == 0:
            return self.aux[j]

        return self.aux[j] - self.aux[i-1]
