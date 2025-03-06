class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 != 0:
            return False
        
        stack = []

        openClose = {
            "(": ")",
            "[": "]",
            "{": "}"
        }

        for i in range(len(s)):
            if s[i] == "(" or s[i] == "[" or s[i] == "{":
                stack.append(s[i])
                continue
            elif len(stack) == 0:
                return False

            if s[i] != openClose[stack.pop()]:
                return False
        
        if len(stack) == 0:
            return True
        else:
            return False
        
print(Solution().isValid("))"))