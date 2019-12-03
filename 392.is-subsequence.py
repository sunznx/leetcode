class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        l1 = len(s)
        l2 = len(t)

        i = 0
        j = 0

        while i < l1 and j < l2:
            if s[i] == t[j]:
                i += 1
                j += 1
            else:
                j += 1
    
        return i == l1

    
    
                
    
                    
        
