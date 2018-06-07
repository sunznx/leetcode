class Solution:
    def isRectangleOverlap(self, rec1, rec2):
        """
        :type rec1: List[int]
        :type rec2: List[int]
        :rtype: bool
        """
        x11, y11, x21, y21 = rec1
        rec2_x1, rec2_y1, rec2_x2, rec2_y2 = rec2
        return not (x11 >= rec2_x2 or x21 <= rec2_x1 or y11 >= rec2_y2 or y21 <= rec2_y1)
