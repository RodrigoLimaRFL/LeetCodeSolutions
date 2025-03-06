class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        
        digitList = []

        while x > 0:
            digitList.append(x % 10)
            x = x // 10

        end = len(digitList) - 1

        for i in range(len(digitList) // 2):
            if digitList[i] != digitList[end - i]:
                return False
            
        return True
